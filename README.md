# JNI

## JNI的实现步骤如下： 
* 1. 编写带有native声明的方法的Java类 
* 2. 使用javac命令编译编写的Java类 
* 3. 使用java 来生成后缀名为.h的头文件 
* 4. 使用其他语言（C、C++）实现本地方法 
* 5. 将本地方法编写的文件生成动态链接库

javah JniTest.java ---> com_jiangwei_ JniTest.h

	#include "com_jiangwei_JniTest.h"
	// 函数实现，类名+函数的名称
	JNIEXPORT jstring JNICALL Java_com_jiangwei_JniTest_getStringFromC
	(JNIEnv* env, jclass jclz){
	    // 将C的字符串转换成Java的字符串
	    return (*env)->NewStringUTF(env, "hello Java");
	}
## 使用java 来生成后缀名为.h的头文件 
类的全路径名称
				
	javah com.jiangwei.JniTest
## 编译动态链接库
	gcc -I/Library/Java/JavaVirtualMachines/jdk1.8.0_102.jdk/Contents/Home/include -c main.c
	gcc -dynamiclib -o libjiangweijni.jnilib main.o
	
这里会报错，说jni.h找不到"jnimd.h"，拷贝一份md过去到/Library/Java/JavaVirtualMachines/jdk1.8.0_102.jdk/Contents/Home/include下面

	/Library/Java/JavaVirtualMachines/jdk1.8.0_102.jdk/Contents/Home/include/jni.h:45:10: fatal error: 
      'jni_md.h' file not found #include "jni_md.h"
      
## java实现

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

      
      




