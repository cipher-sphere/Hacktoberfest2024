//Coded by shreeyachatzz
/*Q. Write a program to convert a Decimal to it's BCD equivalent*/
import java.util.*;
public class Q20
{
    double n; String strr;
    static Scanner sc= new Scanner(System.in);
    Q20()//Constructor to initialise Global Variables
    {
        n=0.0;
        strr="";
    }

    void input()//take a decimal number as input
    {
        System.out.println("Enter the number whose BCD equivalent is to be found:");
        n=sc.nextDouble();
    }

    void display()//to display the BCD number
    {
        System.out.println("The BCD equivalent is: "+strr);
    }

    void convert()//to convert a number to its BCD equivalent
    {
        String bin[]= {"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001"};
        String str= Double.toString(n);
        int l= str.length();
        int index=-9999;//variable to indicate presence of zero
        String st="";//the string that will store the final output
        
        for(int i=0;i<l;i++)
        {
            char ch= str.charAt(i);
            if(ch== '.')
            {
                index=i;
            }
        }
        if(index==-9999)
        {
            for(int i=0;i<l;i++)
            {
                String sss= str.substring(i,(i+1));
                int no= Integer.parseInt(sss);
                st=st+bin[no];
            }
        }
        else
        {
            for(int i=0;i<index;i++)
            {
                String sss= str.substring(i,(i+1));
                int no= Integer.parseInt(sss);
                st=st+bin[no];
            }
            st=st+".";
            for(int i=(index+1);i<l;i++)
            {
                String sss= str.substring(i,(i+1));
                int no= Integer.parseInt(sss);
                st=st+bin[no];
            }
        }
        strr=st;
    }    

    public static void main(String args[])//main method
    {
        Q20 obj= new Q20();//creating object
        obj.input();//calling input
        obj.convert();//calling convert
        obj.display();//calling display
    }
}
/*
OUTPUT(1):

Enter the number whose BCD equivalent is to be found:
25.32
The BCD equivalent is: 00100101.00110010

OUTPUT(2):

Enter the number whose BCD equivalent is to be found:
3.898
The BCD equivalent is: 0011.100010011000

OUTPUT(3):
Enter the number whose BCD equivalent is to be found:
45
The BCD equivalent is: 01000101.0000


 */
