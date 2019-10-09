package com.crazy.crazyndk;

import android.app.Activity;
import android.content.Context;
import android.content.res.Resources;
import android.util.DisplayMetrics;

public class DensityUtil {
	public static float dp2px(Resources resources, float dp) {
		final float scale = resources.getDisplayMetrics().density;
		return dp * scale + 0.5f;
	}

	public static float sp2px(Resources resources, float sp) {
		final float scale = resources.getDisplayMetrics().scaledDensity;
		return sp * scale;
	}
	/**
	 * 根据手机的分辨率从 px(像素) 的单位 转成为 dp
	 */
	public static int px2dip(Context context, float pxValue) {
		final float scale = context.getResources().getDisplayMetrics().density;
		return (int) (pxValue / scale + 0.5f);
	}

	/*
	* 获取屏幕的宽度
	* */
	public static int getScreenWidth(Activity context){
		DisplayMetrics metric = new DisplayMetrics();
		context.getWindowManager().getDefaultDisplay().getMetrics(metric);
		return metric.widthPixels;
	}
	public static int getScreenHeight(Activity context){
		DisplayMetrics metric = new DisplayMetrics();
		context.getWindowManager().getDefaultDisplay().getMetrics(metric);
		return metric.heightPixels;
	}
	public  static int getTxtWidth(Activity context){
		return getScreenWidth(context)/6-(int)sp2px(context.getResources(),3);
	}
}
