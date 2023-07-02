import java.time.LocalTime;

public class InterprocessCommunication {
    public static volatile int shared = 0;

    public static class Response implements Runnable {

        @Override
        public void run() {
            System.out.println("Response:");
            while (shared == 0) {
                Thread.onSpinWait();
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
                System.out.println("Waiting");
            }
            System.out.println(LocalTime.now());
        }
    }

    public static class Request implements Runnable {
        @Override
        public void run() {
            System.out.println("Tell the time now ");
            try {
                Thread.sleep(10000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
            shared = 1;
        }
    }

    public static void main(String[] args) {
        Request request = new Request();
        Response Response = new Response();
        Thread request_thread = new Thread(request);
        Thread response_thread = new Thread(Response);
        response_thread.start();
        request_thread.start();
    }
}