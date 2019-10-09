//
// Created by feaoes on 2018/9/11.
//

#include "header/NDKLibrary.h"
#include <string>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <cstring>
#include <sstream>
#include <header/common.h>
#include "header/AndroidLog.h"

/**
 * 参考
 * https://blog.csdn.net/kgdwbb/article/details/72810251
 */

JNIEXPORT jstring JNICALL Java_com_crazy_crazyndk_ndk_NDKLibrary_getStrigFromJNI
        (JNIEnv *env, jobject jobj) {

    std::string message = "hello word";
    return env->NewStringUTF(message.c_str());
}

JNIEXPORT jstring JNICALL Java_com_crazy_crazyndk_ndk_NDKLibrary_getStrigFromJNIStatic
        (JNIEnv *env, jclass jclazz) {

    const char *message = "i am jni string";
    return env->NewStringUTF(message);

}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_crazy_crazyndk_ndk_NDKLibrary_sendStringToJNI(JNIEnv *env, jobject instance,
                                                       jstring sendMessage_) {
    const char *sendMessage = env->GetStringUTFChars(sendMessage_, 0);

    // TODO

    // env->ReleaseStringUTFChars(sendMessage_, sendMessage);

    if (NULL != sendMessage)
        return env->NewStringUTF(sendMessage);
    else
        return env->NewStringUTF("NULL == sendMessage");
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_crazy_crazyndk_ndk_NDKLibrary_commoneUtils(JNIEnv *env, jobject instance,
                                                    jstring message) {

    const char *str = "hello boy";
    jstring jstr2 = env->NewStringUTF(str);
    LOGE("str: %s", str);

    int len = env->GetStringUTFLength(message);

    const char *_message = env->GetStringUTFChars(message, NULL);
    LOGE("len: utf %d", len);
    LOGE("_message: %s", _message);

    const jchar *mseStr = env->GetStringChars(message, NULL);
    int messageLen = env->GetStringLength(message);
    LOGE("len: %d", len);
    jstring returnStr = env->NewString(mseStr, messageLen);


    const jchar *newJChar = mseStr;

    return returnStr;

}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_crazy_crazyndk_ndk_NDKLibrary_player(JNIEnv *env, jobject instance, jstring message_) {

    /**
     * jstring 转 const char/jchar
     * const char/jchar 转 jstring
     */

    LOGE("NDKLibrary player start ---------------------------------------");

    //TODO jstring -> const char (UTF)
    const char *utfChars = env->GetStringUTFChars(message_, 0);
    //TODO jstring -> const jchar  (UniCode)
    const jchar *unicodeChars = env->GetStringChars(message_, 0);
    LOGE("utfChars: %s", utfChars);

    int len = env->GetStringUTFLength(message_);

    for (int i = 0; i < len; i++) {
        unsigned short sss = unicodeChars[i];
        LOGE("sss: %c", sss);
    }

    //NewStringUTF函数用来生成UTF-8 JNI字符串
    //TODO const char -> jstring (UTF)
    jstring utfStr = env->NewStringUTF(utfChars);

    //NewString函数用来生成Unicode JNI字符串
    //TODO const jchar -> jstring (UniCode)
    int unicodeCharsLen = env->GetStringLength(message_);
    jstring unicodeStr = env->NewString(unicodeChars, unicodeCharsLen);
    LOGE("unicodeCharsLen: %d", unicodeCharsLen);

    env->ReleaseStringUTFChars(message_, utfChars);
    env->ReleaseStringChars(message_, unicodeChars);

    LOGE("utfChars is null ? %d", (utfChars == NULL));
    LOGE("unicodeChars is null ? %d", (unicodeChars == NULL));

    LOGE("NDKLibrary player end ---------------------------------------");

    return utfStr;
}

/**
 *
 * Jni方法中调用Java方法
 *
 * @param env
 * @param instance
 */
extern "C"
JNIEXPORT void JNICALL
Java_com_crazy_crazyndk_ndk_NDKLibrary_calljavaMethodStr(JNIEnv *env, jobject obj) {

    // TODO
    //GetObjectClass函数用来获取Java对象对应的类类型
    jclass jclazz = env->GetObjectClass(obj);
    if (NULL == jclazz)
        return;

    //GetMethodID函数用来获取Java类实例方法的方法ID
    const char *methodName = "javaMethodStr";
    const char *sign = "(I)Ljava/lang/String;";
    jmethodID methodId = env->GetMethodID(jclazz, methodName, sign);
    if (NULL == methodId)
        return;

    //Call<Type>Method函数用来调用Java类实例特定返回值的方法
    jobject jobj = env->CallObjectMethod(obj, methodId, 666);
    jstring strValue = (jstring) jobj;

    //
    const char *charValue = env->GetStringUTFChars(strValue, 0);
    LOGE("charValue: %s", charValue);
}

/**
 *
 * Jni方法中调用Java对象成员
 *
 * @param env
 * @param instance
 * @param person
 * @return
 */
extern "C"
JNIEXPORT jstring JNICALL
Java_com_crazy_crazyndk_ndk_NDKLibrary_jniCallJavaObjcetField(JNIEnv *env, jobject instance,
                                                              jobject person) {

    // TODO
    const char *errorMeg;

    //GetObjectClass函数用来获取Java对象对应的类类型
    jclass jclazz = env->GetObjectClass(person);
    if (NULL == jclazz) {
        errorMeg = "null == jclazz";
        return env->NewStringUTF(errorMeg);
    }

    //GetFieldID函数用来获取Java字段的字段ID
    //name
    const char *fieldName = "name";
    const char *fieldSign = "Ljava/lang/String;";
    const char *name;
    jstring willReturnStr = NULL;
    jfieldID nameFieldId = env->GetFieldID(jclazz, fieldName, fieldSign);
    if (NULL == nameFieldId) {
        errorMeg = "null == nameFieldId";
        LOGE("%s", errorMeg);
        return env->NewStringUTF(errorMeg);
    } else {
        //Get<Type>Field用来获取Java类字段的值
        jstring jname = (jstring) env->GetObjectField(person, nameFieldId);
        name = env->GetStringUTFChars(jname, 0);
        willReturnStr = env->NewStringUTF(name);
        LOGE("name: %s", name);
        env->ReleaseStringUTFChars(jname, name);
    }

    //age
    fieldName = "age";
    fieldSign = "I";
    int age = 0;
    jfieldID ageFieldId = env->GetFieldID(jclazz, fieldName, fieldSign);
    if (NULL != ageFieldId) {
        age = env->GetIntField(person, ageFieldId);
        LOGE("age: %d", age);
    } else {
        errorMeg = "null == ageFieldId";
        LOGE("%s", errorMeg);
        return env->NewStringUTF(errorMeg);
    }

    std::string str = "age: ";

    // return (NULL != willReturnStr) ? willReturnStr : env->NewStringUTF(appendStr);
    return env->NewStringUTF(str.data());
}


JNIEnv *envGlobal;
JavaVM *jvm = NULL;

extern "C"
JNIEXPORT jobject JNICALL
Java_com_crazy_crazyndk_ndk_NDKLibrary_getPersonFromJni(JNIEnv *env, jobject instance, jint id,
                                                        jstring name,
                                                        jint age) {

    LOGE(".....-1......");

    // TODO
    Person *_person = new Person();
    _person->id = id;
    _person->age = age;
    const char *nameChars = env->GetStringUTFChars(name, 0);
    //const char *nameChars = "三年六班";
    // _person->name = (char *) nameChars;

    char arrays[30];
    strcpy(arrays, nameChars);
    _person->name = &arrays[0];

    LOGE(".....00......");

    //获取jclass的实例
    jclass jPersonClazz = env->FindClass("com/crazy/crazyndk/ndk/Person");
    LOGE(".....01......");

    //获取Person的字段ID
    jfieldID jID = env->GetFieldID(jPersonClazz, "id", "I");
    jfieldID jNameID = env->GetFieldID(jPersonClazz, "name", "Ljava/lang/String;");
    jfieldID jAgeID = env->GetFieldID(jPersonClazz, "age", "I");

    LOGE(".....02......");

    //创建Person对象
    jobject jPerson = env->AllocObject(jPersonClazz);
    env->SetIntField(jPerson, jID, _person->id);
    if (NULL != _person->name)
        env->SetObjectField(jPerson, jNameID, env->NewStringUTF(_person->name));
    env->SetIntField(jPerson, jAgeID, _person->age);

    env->ReleaseStringUTFChars(name, nameChars);
    return jPerson;
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_crazy_crazyndk_ndk_NDKLibrary_jniOperateFile(JNIEnv *env, jobject instance,
                                                      jstring fileName_) {

    bool isSuccess = false;
    const char *fileName = env->GetStringUTFChars(fileName_, 0);

    // TODO
    const char *content = "Hello Word!.......\n";
    const char *path = "/sdcard/JniFile.txt";
    const char *mode = "a+";

    FILE *file = fopen(path, mode);
    if (NULL != file) {
        fputs(content, file);
        fflush(file);
        fclose(file);
        isSuccess = true;
    } else {
        isSuccess = false;
    }

    env->ReleaseStringUTFChars(fileName_, fileName);


    return (jboolean) (isSuccess ? JNI_TRUE : JNI_FALSE);
}