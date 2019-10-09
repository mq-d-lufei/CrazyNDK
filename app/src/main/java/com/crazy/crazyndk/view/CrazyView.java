package com.crazy.crazyndk.view;

import android.content.Context;
import android.support.annotation.Nullable;
import android.util.AttributeSet;
import android.util.Log;
import android.view.View;

import com.crazy.crazyndk.DensityUtil;

/**
 * Created by feaoes on 2018/9/13.
 */

public class CrazyView extends View {

    public static final String TAG = "CrazyView";

    public CrazyView(Context context) {
        super(context);
    }

    public CrazyView(Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
    }

    @Override
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {

        int widthMode = MeasureSpec.getMode(widthMeasureSpec);
        int widthSize = MeasureSpec.getSize(widthMeasureSpec);
        int heightMode = MeasureSpec.getMode(heightMeasureSpec);
        int heightSize = MeasureSpec.getSize(heightMeasureSpec);

        Log.e(TAG, "widthMeasureSpec: " + MeasureSpec.toString(widthMeasureSpec) + " -- widthSize: " + widthSize + " -- widthSize: " + DensityUtil.px2dip(this.getContext(), widthSize));
        Log.e(TAG, "widthMode: " + widthMode + " -- widthSize: " + widthSize + " -- widthSize: " + DensityUtil.px2dip(this.getContext(), widthSize));
        Log.e(TAG, "heightMeasureSpec: " + MeasureSpec.toString(heightMeasureSpec) + " -- heightSize: " + heightSize + " -- heightSize: " + DensityUtil.px2dip(this.getContext(), heightSize));
        Log.e(TAG, "heightMode: " + heightMode + " -- heightSize: " + heightSize + " -- heightSize: " + DensityUtil.px2dip(this.getContext(), heightSize));

        //super.onMeasure(widthMeasureSpec, heightMeasureSpec);

        setMeasuredDimension(getMeasureSize("width", widthMeasureSpec), getMeasureSize("height", heightMeasureSpec));

        Log.e(TAG, "getWidth: " + getWidth() + " -- widthSize: " + DensityUtil.px2dip(this.getContext(), getWidth()) + " -- getMeasuredWidth()" + getMeasuredWidth());
        Log.e(TAG, "getHandler: " + getHeight() + " -- getHeight: " + DensityUtil.px2dip(this.getContext(), getHeight()) + " -- getMeasuredHeight()" + getMeasuredHeight());

    }

    int defalueSize = 200;

    public int getMeasureSize(String wOrH, int measureSpec) {

        int resultSize = defalueSize;
        int measureMode = MeasureSpec.getMode(measureSpec);
        int measureSize = MeasureSpec.getSize(measureSpec);

        switch (measureMode) {
            case MeasureSpec.EXACTLY:
                resultSize = measureSize;
                break;
            case MeasureSpec.AT_MOST:
                resultSize = Math.min(measureSize, defalueSize);
                break;
            case MeasureSpec.UNSPECIFIED:
                resultSize = defalueSize;
                break;
            default:
                break;
        }

        return resultSize;
    }

    @Override
    protected void onSizeChanged(int w, int h, int oldw, int oldh) {

        Log.e(TAG, String.format("onSizeChanged: w%s,%s,%s,%s", w, h, oldw, oldh));

        super.onSizeChanged(w, h, oldw, oldh);

        Log.e(TAG, String.format("onSizeChanged2: w%s,%s,%s,%s", w, h, oldw, oldh));


    }

    @Override
    protected void onLayout(boolean changed, int left, int top, int right, int bottom) {
        Log.e(TAG, "onLayout");

        Log.e(TAG, "getWidth: " + getWidth() + " -- widthSize: " + DensityUtil.px2dip(this.getContext(), getWidth()) + " -- getMeasuredWidth()" + getMeasuredWidth());
        Log.e(TAG, "getHandler: " + getHeight() + " -- getHeight: " + DensityUtil.px2dip(this.getContext(), getHeight()) + " -- getMeasuredHeight()" + getMeasuredHeight());

        super.onLayout(changed, left, top, right, bottom);

        Log.e(TAG, "getWidth: " + getWidth() + " -- widthSize: " + DensityUtil.px2dip(this.getContext(), getWidth()) + " -- getMeasuredWidth()" + getMeasuredWidth());
        Log.e(TAG, "getHandler: " + getHeight() + " -- getHeight: " + DensityUtil.px2dip(this.getContext(), getHeight()) + " -- getMeasuredHeight()" + getMeasuredHeight());


    }
}
