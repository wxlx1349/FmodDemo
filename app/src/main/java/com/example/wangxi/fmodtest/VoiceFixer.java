package com.example.wangxi.fmodtest;

/**
 * Created by wangxi on 2017/2/13.
 * <p>
 * description :
 * version code: 1
 * create time : 2017/2/13
 * update time : 2017/2/13
 * last modify : wangxi
 */

public class VoiceFixer {
    public static final int MODE_NORMAL = 0;
    public static final int MODE_LUOLI = 1;
    public static final int MODE_DASHU = 2;
    public static final int MODE_JINGSONG = 3;
    public static final int MODE_GAOGUAI = 4;
    public static final int MODE_KONGLING = 5;

    public native static void fix(String path, int mode);

    static {
        System.loadLibrary("fmod");
        System.loadLibrary("fmodL");
        System.loadLibrary("native-lib");
    }

}
