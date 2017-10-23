(*Miron Oana Pb3*)
datatype 'a list=cons of 'a*'a list|nil;

datatype 'a Ord=Ord of 'a *'a -> bool;

fun help (a,nil) = a
  | help (a,cons(h,t)) = help(cons(h,a),t);

fun reverse(a:'a list)=help(nil,a);

fun concat(a,nil)=a
  | concat(nil,b)=b
  | concat(a:'a list,cons(h,t):'a list)= concat(reverse(cons(h,reverse(a))),t);

val IntSmaller: int Ord = Ord ( fn(x,y)=> x<=y );
val Divisible: int Ord=Ord(fn(x,y)=> x mod y=0);
val Lexicographic: string Ord=Ord(fn(x,y)=> x<=y);

fun sorted(nil,ord:'a Ord)=true
  | sorted(cons(a,nil):'a list,ord:'a Ord)=true
  | sorted(cons(a,cons(b,t)):'a list,ord:'a Ord)=let val Ord(func)=ord; in
                  if func(a,b)=true then sorted(cons(b,t),ord) else false end;

sorted(cons(1,cons(2,nil)),IntSmaller);
sorted(cons(2,cons(3,cons(1,nil))),IntSmaller);
sorted(cons(2,cons(3,cons(1,nil))),Divisible);
sorted(cons(45,cons(5,cons(1,nil))),Divisible);
sorted(cons("ok",cons("mama",cons("send help",nil))),Lexicographic);
sorted(cons("ok",cons("ok1",cons("ok2",nil))),Lexicographic);
