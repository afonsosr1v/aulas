/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package helloworld;

import java.util.Date;

/**
 *
 * @author nobrega
 */
public class HelloWorld {
    public int n;
    public String str;
    public java.util.Date data;
    
    
    HelloWorld(int a, String b){
        n = a;
        str = b;
        data= new Date();
        
    }
    
    
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        HelloWorld stringfinal = new HelloWorld(0, "2023");
        try{
           stringfinal.n = Integer.parseInt(stringfinal.str);
        } catch (NumberFormatException e) {
            System.out.println("Número inválido" +e);
        }       
        System.out.println("Hello World " + stringfinal.n);
        java.text.SimpleDateFormat formatter = new java.text.SimpleDateFormat("E hh:mm:ss 'em' dd.MM.yyyy");
        System.out.println("A data actual é " + formatter.format(stringfinal.data));
    }
}


