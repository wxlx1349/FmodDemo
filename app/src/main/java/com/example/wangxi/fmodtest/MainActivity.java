package com.example.wangxi.fmodtest;

import android.app.Activity;
import android.os.Bundle;
import android.os.Environment;
import android.view.View;
import android.widget.Toast;

import java.io.File;

public class MainActivity extends Activity {
    private String path;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main_activity);
        path = Environment.getExternalStorageDirectory().getAbsolutePath() + File.separatorChar + "wave.mp3";
        File file = new File(path);
        Toast.makeText(this, "文件是否存在" + file.exists() + "path=" + path, Toast.LENGTH_LONG).show();
    }

    public void voice(View view) {
        switch (view.getId()) {
            case R.id.voice_old:
                VoiceFixer.fix(path, VoiceFixer.MODE_NORMAL);
                break;
            case R.id.voice_luoli:
                VoiceFixer.fix(path, VoiceFixer.MODE_LUOLI);
                break;
            case R.id.voice_dashu:
                VoiceFixer.fix(path, VoiceFixer.MODE_DASHU);
                break;
            case R.id.voice_kongling:
                VoiceFixer.fix(path, VoiceFixer.MODE_KONGLING);
                break;
            case R.id.voice_jingsong:
                VoiceFixer.fix(path, VoiceFixer.MODE_JINGSONG);
                break;
            case R.id.voice_gaoguai:
                VoiceFixer.fix(path, VoiceFixer.MODE_GAOGUAI);
                break;
            default:
        }
    }
}
