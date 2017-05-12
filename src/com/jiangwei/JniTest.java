package com.jiangwei;

public class JniTest {
	static String name = "a";

	public native static String getStringFromC();

	static {
		System.loadLibrary("from_c_jni");
	}

	public static void main(String[] args) {
		JniTest t = new JniTest();
		System.out.println(t.getStringFromC());
	}
}
