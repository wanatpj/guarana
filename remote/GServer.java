import java.io.*;
import java.net.*;
import java.util.Scanner;
class GServer{
    public static boolean valid_usr(String usr, String passwd){
	return true;
    }
    public static String response(String usr, int mood){
	return "";
    }
    public static void main(String[] args){
	System.out.println("Server for Guarana's clients");
	System.out.println("GServer is beginning");
	try {
	    ServerSocket s = new ServerSocket(14014);
	    Socket GClient;
	    while(true){
		System.out.println("Waiting for connection...");
		GClient = s.accept();
		//_____________________try__________________________
		/*

Exception in thread "main" java.util.NoSuchElementException
        at java.util.Scanner.throwFor(Scanner.java:838)
        at java.util.Scanner.next(Scanner.java:1347)
        at GServer.main(GServer.java:23)

		*/
		    InputStream ins = GClient.getInputStream();
		    Scanner in = new Scanner(ins);
		    String usr = in.next();
		    String passwd = in.next();
		    if(valid_usr(usr, passwd)){
			int what = Integer.parseInt(in.next());
			String resp = response(usr, what);
			OutputStream osr = GClient.getOutputStream();
			PrintWriter pwr = new PrintWriter(osr, true);
			pwr.print(resp);
			osr.close();
		    }
		//__________________________________________________
		GClient.close();
		if(false) break;
	    }
	    s.close();
	    System.out.println("GServer - closed");
	}
	catch(IOException e){
	    System.out.println(e);
	}
    }
}
