//Oana miron
//o.miron@jacobs-university.de
//P1

import java.math.BigInteger;
import java.util.Scanner;
public class gcd
{
  public static void main(String[] args)
  {
    BigInteger m;
    BigInteger n;
	Scanner sc=new Scanner(System.in);
	BigInteger b=BigInteger.ZERO;
  m=sc.nextBigInteger();
	n=sc.nextBigInteger();
	if(n.compareTo(b)==0)
    {
        System.out.println(m);
    }
    else
    {
        if(m.compareTo(b)==0)
        {
            System.out.println(n);
        }
        else
        {
            do
            {
                if(n.compareTo(m)>0)
                {
                n=n.add(m.negate());
                }
                else
                {
                m=m.add(n.negate());
                }
            }
        while(n.compareTo(m)!=0);
        System.out.println(n);
        }
    }
  }
}
