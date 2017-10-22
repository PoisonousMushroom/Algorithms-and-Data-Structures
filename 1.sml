(*Oana Miron P1.2 Sml*)
datatype rational= Fr of IntInf.int*IntInf.int;

exception NotRuleRational;
(*When the problem definition is not respected*)

fun gcd (m: IntInf.int,0)=m
  | gcd (0,m: IntInf.int)=m
  | gcd (m:IntInf.int,n:IntInf.int)=
    if n>m then
      let val (_,v)=IntInf.divMod(n,m)
          val b=m
          in gcd(v,b) end
    else
      let val (_,v)=IntInf.divMod(m,n)
          val b=n
      in gcd(v,b) end;

fun Simplify(Fr(a,b))=let val g=gcd(a,b)
                          val (n,_)=IntInf.divMod(a,g)
                          val (m,_)=IntInf.divMod(b,g)
                      in  Fr(n,m)
                      end;

fun add(Fr(a,b),Fr(c,d))=if b<=0 orelse d<=0 then raise NotRuleRational
                         else Simplify(Fr(a*d+b*c,b*d));
fun mult(Fr(a,b),Fr(c,d))=if b<=0 orelse d<=0 then raise NotRuleRational
                         else Simplify(Fr(a*c,b*d));
fun invmult(Fr(a,b))=if b<=0 then raise NotRuleRational
                     else if a=0 then Fr(0,1) else Simplify(Fr(b,a));
fun invadd(Fr(a,b))=if b<=0 then raise NotRuleRational
                    else Fr(~1*a,b);

add(Fr(5,10),Fr(5,2));
mult(Fr(2,3),Fr(1000000000,20301));
invadd(Fr(~1231,12310));
invmult(Fr(1313,1313));
