
import java.util.Scanner;

public class Vowels {

	private static Scanner scan2;

	public static void main(String[] args) {
		
		int acount = 0,ecount = 0,icount = 0,ocount = 0,ucount = 0,consonants = 0;
	    int i = 0, spaces = 0, length = 0, words = 0;
		
		System.out.println("Please enter the sentence: ");
		scan2 = new Scanner(System.in);
		String input = scan2.nextLine();
		
		String j;
		length = input.length();
		for (i = 0; i < length; i++)
		{
		  j = input.substring(i, i + 1);

		  if (j.equalsIgnoreCase("a") == true)
		    acount++;
		  else if (j.equalsIgnoreCase("e") == true)
		    ecount++;
		  else if (j.equalsIgnoreCase("i") == true)
		    icount++;
		  else if (j.equalsIgnoreCase("o") == true)
		    ocount++;
		  else if (j.equalsIgnoreCase("u") == true)
		    ucount++;
		  else if (j.equalsIgnoreCase(" ") == true)
			spaces++;
		  else 
			consonants++;	  
		}
	       words = (spaces + 1);
		
		System.out.println("Vowel A: " + acount );
		System.out.println("Vowel E: " + ecount );
		System.out.println("Vowel I: " + icount );
		System.out.println("Vowel O: " + ocount );
		System.out.println("Vowel U: " + ucount );
		System.out.println("Consonants: " + consonants );
		System.out.println("Spaces: " + spaces );
		System.out.println("Words: " + words );
	}
}
