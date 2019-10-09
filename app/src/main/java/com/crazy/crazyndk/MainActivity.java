package com.crazy.crazyndk;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;

import com.crazy.crazyndk.ndk.NDKLibrary;
import com.crazy.crazyndk.ndk.Person;

public class MainActivity extends AppCompatActivity {

    public String TAG = "MainActivity";

    // Used to load the 'native-lib' library on application startup.

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        Button jniBt = findViewById(R.id.sample_text);
        jniBt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                initRunNDKLibrary();
            }
        });

    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    NDKLibrary ndkLibrary;

    public void initRunNDKLibrary() {
        ndkLibrary = new NDKLibrary();

        String strigFromJNI = ndkLibrary.getStrigFromJNI();
        Log.e(TAG, "strigFromJNI:" + strigFromJNI);

        Log.e(TAG, "getStrigFromJNIStatic:" + NDKLibrary.getStrigFromJNIStatic());


        String sendFromString = ndkLibrary.sendStringToJNI("i am java string ");
        Log.e(TAG, "sendFromString:" + sendFromString);

        String commone = ndkLibrary.commoneUtils("common utils ...");
        Log.e(TAG, "commone: " + commone);

        String player = ndkLibrary.player("player ...");
        Log.e(TAG, "player return string : " + player);

        ndkLibrary.calljavaMethodStr();

        Person person = new Person(1, "小明", 18);
        String returnValue = ndkLibrary.jniCallJavaObjcetField(person);
        Log.e(TAG, "returnValue return string : " + returnValue);

        Person personFromJni = ndkLibrary.getPersonFromJni(1, "Android", 18);
        Log.e(TAG, "personFromJni: " + personFromJni);

        boolean isWrite = ndkLibrary.jniOperateFile("sdf");
        Log.e(TAG, "isWrite: " + isWrite);
    }

    public void go_to_crazy_view(View view) {
      //  startActivity(new Intent(this, CrazyViewActivity.class));
    }
}
