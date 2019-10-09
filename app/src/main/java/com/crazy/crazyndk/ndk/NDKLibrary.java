package com.crazy.crazyndk.ndk;

import android.util.Log;

/**
 * Created by feaoes on 2018/9/11.
 */

public class NDKLibrary {

    static {
        System.loadLibrary("NDKLibrary");
    }

    public native String sendStringToJNI(String sendMessage);

    public native String getStrigFromJNI();

    public static native String getStrigFromJNIStatic();


    public native String commoneUtils(String message);

    public native String player(String message);

    public native void calljavaMethodStr();

    public String javaMethodStr(int intValue) {
        Log.e("NDKLibrary", "javaMethodStr is executing");
        return "i am java string method";
    }

    public native String jniCallJavaObjcetField(Person person);

    public native Person getPersonFromJni(int id, String name, int age);

    /**
     * 文件操作
     */
    public native boolean jniOperateFile(String fileName);

}
