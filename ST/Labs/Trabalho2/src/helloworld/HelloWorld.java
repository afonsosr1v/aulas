/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package helloworld;

import java.util.Date;
import java.util.HashMap;
import java.util.Iterator;

/**
 *
 * @author nobrega
 */
public class HelloWorld {
    public int n;
    public String str;
    public java.util.Date data;
    private int vect[];
    private HashMap<String,String> list;
    
    
    HelloWorld(int a, String b){
        n = a;
        str = b;
        data= new Date();
        vect = new int[5];
        
        int i = 0;
        for(i=0;i<5; i++){
            vect[i] = 2*i;
        }
        
        list = new HashMap<String,String> ();
        list.clear();
        list.put("RATO", "23:00 a 1:00");
        list.put("BOI", "1:00 as 3:00");
        list.put("TIGRE", "3:00 as 5:00");
        list.put("COELHO", "5:00 as 7:00");
        list.put("DRAGAO", "7:00 as 9:00");
        list.put("SERPENTE", "9:00 as 11:00");
        list.put("CAVALO", "11:00 as 13:00");
        list.put("CABRA","13:00 as 15:00");
        list.put("MACACO", "15:00 as 17:00");
        list.put("GALO", "17:00 as 19:00");
        list.put("CAO", "19:00 as 21:00");
        list.put("PORCO", "21:00 as 23:00");
        
    }
    
    public void printarDrenas() {
        int j;
        for(j=0;j<5; j++){
            System.out.println("Elemento " +j+ " = " + vect[j]) ;
        }
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
        
        stringfinal.printarDrenas();
    }
}


