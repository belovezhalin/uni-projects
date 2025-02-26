package com.packt.datastructuresandalg.setup;

public class HelloWorld {
    public String seyHello() {
        return "Witaj, świecie!";
    }

    public static void main(String []args) {
        System.out.println((new HelloWorld()).seyHello());
    }
}
