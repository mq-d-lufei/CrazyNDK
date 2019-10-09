package com.crazy.crazyndk.view;

import android.content.Context;
import android.support.annotation.Nullable;
import android.util.AttributeSet;
import android.widget.LinearLayout;

/**
 * Created by feaoes on 2018/9/14.
 */

public class CrazyGroupView extends LinearLayout {


    public CrazyGroupView(Context context) {
        super(context);
    }

    public CrazyGroupView(Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
    }

    @Override
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
        super.onMeasure(widthMeasureSpec, heightMeasureSpec);

    }
}
