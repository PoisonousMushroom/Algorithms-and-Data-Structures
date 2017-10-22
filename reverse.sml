(*P2. Miron Oana Functional language*)
datatype 'a list=cons of 'a*'a list|nil;

fun help (a,nil) = a
  | help (a,cons(h,t)) = help(cons(h,a),t);

fun reverse(a:'a list)=help(nil,a);

fun concat(a,nil)=a
  | concat(nil,b)=b
  | concat(a:'a list,cons(h,t):'a list)= concat(reverse(cons(h,reverse(a))),t);

reverse(cons(1,cons(2,cons(3,nil))));
concat(cons(1,nil),cons(3,cons(4,nil)));
