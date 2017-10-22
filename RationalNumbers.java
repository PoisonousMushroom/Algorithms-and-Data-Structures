//Oana Miron
//o.miron@jacobs-university.de
//Pb2
import java.math.BigInteger;
import java.util.Scanner;
public class RationalNumbers
{
  private BigInteger a;
  private BigInteger b;
  //class constructors
  public RationalNumbers(BigInteger nominator,BigInteger denominator)
  {
    a=nominator;
    b=denominator;
  }
  public RationalNumbers()
  {
    a=BigInteger.ZERO;
    b=new BigInteger("1");
  }
  //two methods (setters)
  public void seta(BigInteger ne)
  {
    a=ne;
  }
  public void setb(BigInteger ne)
  {
    b=ne;
  }
  //print
  public void print()
  {
    System.out.println("The result is "+a+"/"+b);
  }
  //gcd
  public BigInteger gcd(BigInteger m, BigInteger n)
  {
    BigInteger b=BigInteger.ZERO;
  	if(n.compareTo(b)==0)
      {
          return m;
      }
      else
      {
          if(m.compareTo(b)==0)
          {
              return n;
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
              return n;
          }
        }
    }
  //simplification
  public RationalNumbers Simplify(RationalNumbers x)
  {
    BigInteger g=gcd(x.a,x.b);
    RationalNumbers z=new RationalNumbers(x.a.divide(g),x.b.divide(g));
    return z;
  }
  //addition
  public void add(RationalNumbers x, RationalNumbers y)
  {
    System.out.println("Addition");
    RationalNumbers z=new RationalNumbers((x.a.multiply(y.b)).add(y.a.multiply(x.b)),x.b.multiply(y.b));
    Simplify(z).print();
  }
  //multiplication
  public void mult(RationalNumbers x,RationalNumbers y)
  {
    System.out.println("Multiplication");
    RationalNumbers z=new RationalNumbers(x.a.multiply(y.a),x.b.multiply(y.b));
    Simplify(z).print();
  }
  //multiplicative inverse
  public void invmult(RationalNumbers x)
  {
    System.out.println("Multiplicative inverse");
    RationalNumbers z=new RationalNumbers(x.b,x.a);
    Simplify(z).print();
  }
  //additive inverse
  public void invadd(RationalNumbers x)
  {
    System.out.println("Additive inverse");
    RationalNumbers z=new RationalNumbers(x.a.negate(),x.b);
    z.print();
  }
  //main
  public static void main(String[] args)
  {
    try
    {
        RationalNumbers obj = new RationalNumbers();
        obj.run (args);
    }
    catch (Exception e)
    {
        e.printStackTrace();
    }
  }
  public void run(String[] args) throws Exception
  {
    Scanner sc=new Scanner(System.in);
    RationalNumbers x=new RationalNumbers(sc.nextBigInteger(),sc.nextBigInteger());
    RationalNumbers y=new RationalNumbers(sc.nextBigInteger(),sc.nextBigInteger());
    BigInteger b=BigInteger.ZERO;
    if(x.b.compareTo(b)<=0||y.b.compareTo(b)<=0)
    {
      System.out.println("The values don't respect the problem rules.");
    }
    else
    {
      invadd(x);
      add(x,y);
      invmult(x);
      mult(x,y);
    }
  }
}
