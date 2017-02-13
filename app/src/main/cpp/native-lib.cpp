#include <jni.h>
#include <stdlib.h>
#include <fmod.hpp>
#include <unistd.h>
#include "com_example_wangxi_fmodtest_VoiceFixer.h"

#define MODE_NORMAL 0
#define MODE_LUOLI 1
#define MODE_DASHU 2
#define MODE_JINGSONG 3
#define MODE_GAOGUAI 4
#define MODE_KONGLING 5

using namespace FMOD;

//音效处理
JNIEXPORT void JNICALL Java_com_example_wangxi_fmodtest_VoiceFixer_fix
        (JNIEnv *env, jclass jcls, jstring path_jstr, jint mode) {
    System *system;
    Sound *sound;
    Channel *channel;
    bool isplaying = true;
    DSP *dsp;
    float frequency;

    System_Create(&system);
    system->init(32, FMOD_INIT_NORMAL, NULL);
    const char *path_cstr = env->GetStringUTFChars(path_jstr, NULL);
    system->createSound(path_cstr, FMOD_DEFAULT, NULL, &sound);
    try {
        switch (mode) {
            case MODE_NORMAL:
                system->playSound(sound, NULL, false, &channel);
                break;
            case MODE_LUOLI:
                //创建音效
                system->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT, &dsp);
                //设置值
                dsp->setParameterFloat(FMOD_DSP_TYPE_PITCHSHIFT, 2.5);
                system->playSound(sound, NULL, false, &channel);
                channel->addDSP(0, dsp);
                break;
            case MODE_DASHU:
                //创建音效
                system->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT, &dsp);
                //设置值
                dsp->setParameterFloat(FMOD_DSP_TYPE_PITCHSHIFT, 0.8);
                system->playSound(sound, NULL, false, &channel);
                channel->addDSP(0, dsp);
                break;
            case MODE_KONGLING: //重叠
                //创建音效
                system->createDSPByType(FMOD_DSP_TYPE_ECHO, &dsp);
                //设置值
                dsp->setParameterFloat(FMOD_DSP_ECHO_DELAY, 300);
                dsp->setParameterFloat(FMOD_DSP_ECHO_FEEDBACK, 20);
                system->playSound(sound, NULL, false, &channel);
                channel->addDSP(0, dsp);
                break;
            case MODE_GAOGUAI:
                system->createDSPByType(FMOD_DSP_TYPE_NORMALIZE, &dsp);
                system->playSound(sound, NULL, false, &channel);
                channel->addDSP(0, dsp);
                channel->getFrequency(&frequency);
                frequency = frequency * 1.6;
                channel->setFrequency(frequency);
                break;
        }

    } catch (...) {
        goto end;
    }


    system->update();

    //检查释放播放完成
    while (isplaying) {
        channel->isPlaying(&isplaying);
        sleep(1);
    }

    end:
    //释放
    system->close();
    system->release();

    env->ReleaseStringUTFChars(path_jstr, path_cstr);
}
