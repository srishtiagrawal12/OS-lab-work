
package operatingsystem;
 
import java.util.Scanner;


public class Producerconsumer 
{  static int mutex=1,E=5,F=0;
   
    public static int wait(int S)
    {
        return(--S);
    }
    
    public static int signal(int S)
    {
        return(++S);
    }
 public static void producer()
    {
       mutex=wait(mutex);
       F=signal(F);
       E=wait(E);
       
        System.out.println("Producer executing");
        mutex=signal(mutex);
       
    }
    
    public static void consumer()
    {
        mutex=wait(mutex);
        F=wait(F);
        E=signal(E);
                
        
        System.out.println("Consumer executing");
        mutex=signal(mutex);
    }
    
    public static void producerCall()
    {
        if(mutex==1 && F!=5)
            producer();
        else
            System.out.println("Producer wait");
    }
     public static void consumerCall()
    {
        if(mutex==1 && E!=5)
            consumer();
        else
            System.out.println("consumer wait");
    }
    
    
    
    public static void main(String args[])
    {
         int choice=0;
        Scanner scan=new Scanner(System.in);
        
        do
        {
            System.out.println("Enter your choice");
            System.out.println("1.Producer");
            System.out.println("2.Consumer");
            System.out.println("3.exit");
            
            choice=scan.nextInt();
            
            switch(choice)
            {
                case 1:producerCall();break;
                case 2:consumerCall();break;
                case 3:System.exit(0);
                
            }
                
        } while(choice!=0);
        
    }
}
