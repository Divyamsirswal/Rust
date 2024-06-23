import java.util.*;

public class basic{
	private static String[] units = {
		"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
	};
	private static String[] tens = {
		"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
	};
	public static String convert(int x){
		if(x<0 && x>100000){
			throw new IllegalArgumentException("Amount must be in range");
		}
		if(x==0){
			return "Zero";
		}
		return convertAmount(x);
	}
	public static String convertAmount(int amt){
		if(amt<20){
			return units[amt];
		}
		if(amt<100){
			return tens[amt/10] + (amt%10 != 0 ? " "+units[amt%10]:"");
		}
		if(amt<1000){
			return units[amt/100] + " Hundred"+(amt%100!=0 ? " "+convertAmount(amt%100):"");
		}
		if(amt<100000){
			return convertAmount(amt/1000) + " Thousand" + (amt%1000!=0 ? " "+convertAmount(amt%1000):"");
		}
		return "Amount out of range";
	}
	public static void main(String args[]){
		int amt = 423423443;
		System.out.println(amt);
		System.out.println(convert(amt));
	}
}