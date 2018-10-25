package javaapplication1;

/**
 *
 * @author Student
 */
public class Bankers {
   static int[][] allocation={{1,2,2,1},{1,0,3,3},{1,2,1,0}};
   static int[][] max={{2,2,2,2},{1,1,3,4},{1,2,2,0}};
   static  int[][] need=new int[4][4];
   static int[] available={3,1,1,2};
   static boolean[][] finish={{false},{false},{false},{false}};
    
    static boolean checkNeed(int i) throws Exception
    {
        int f=0;
        
        
        for(int j=0;j<4;j++)
        {
            
           if(need[i][j]<available[j])
           {
               f++;
               
           }
        }
        if(f==4)
        {
            for(int j=0;j<3;j++)
            {
                available[j]=available[j]+allocation[i][j];
            }
            //System.out.println("3");
            return true;
            
        }
        else
            return false;
    }
    public static void main(String[] args) throws Exception {
       for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
            need[i][j]=max[i][j]-allocation[i][j];   
            }
        } 
       int counter=0,count=0;
        while(counter<5)
        {
           for(int i=0;i<3;i++)
           {
               if(checkNeed(i))
               {
                   count++;
                   System.out.println("Process "+i+"has been allocated all it's required resources");
               }
           }
           if(count==3)
               break;
           counter++;
       }
        if(count==3)
           {
               System.out.println("Safe State");
           }
        else
            System.out.println("Unsafe state");
}
}
© 2018 GitHub, Inc.