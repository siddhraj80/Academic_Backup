class OddThread extends Thread{

    public void run(){

        int i = 1;

        while(i <= 100){

            try {
                if(i % 2 != 0){
                    System.out.println("Odd number :" + i);
                    Thread.sleep(500);
                }
                
            } catch (Exception e) {
                e.printStackTrace();
            }

            i++;
        }
        
    }
}

class PrimeThread implements Runnable{

    @Override 
    public void run(){

        int i = 1;
        boolean found = false;

        while(i <= 100){

            int j = 2;
            found = false;

            try {
                while(j < i){
                    if(i % j == 0){

                        found = true;
                        break;
                    }
                    j++;
                }

                if(found == false){
                    System.out.println("Prime number :" + i);
                    Thread.sleep(1000);
                }
                
            } catch (Exception e) {
                e.printStackTrace();
            }

            i++;
        }
        
    }
}

public class Program13 {
    public static void main(String[] args){

        OddThread ot = new OddThread();
        PrimeThread pt = new PrimeThread();

        Thread pThread = new Thread(pt);
        ot.start();
        pThread.start();

    }
}

