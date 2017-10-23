(*Miron Oana Pb2*)
datatype 'a list=cons of 'a*'a list|nil;

datatype 'a Ord=Ord of 'a *'a -> bool;

(*bubblesorting*)
fun bubblesort(nil,ord)=nil
  | bubblesort(cons(x,nil):'a list,ord)=cons(x,nil)
  | bubblesort(cons(a,cons(b,t)):'a list,ord:'a Ord)=let val Ord(func)=ord; in
                  if func(a,b)=false then cons(b,bubblesort(cons(a,t),ord))
                  else cons(a,bubblesort(cons(b,t),ord)) end;

(*checks if function is sorted*)
fun sorted(nil,ord:'a Ord)=true
  | sorted(cons(a,nil):'a list,ord:'a Ord)=true
  | sorted(cons(a,cons(b,t)):'a list,ord:'a Ord)=let val Ord(func)=ord; in
               if func(a,b)=true then sorted(cons(b,t),ord) else false end;

(*check if sorted for bubblesort*)
fun sortbubble(nil,ord)=nil
  | sortbubble(x:'a list,ord)= if sorted(x,ord)=true then x else sortbubble(bubblesort(x,ord),ord);


fun partition(pivot, nil,ord)=(nil,nil)
  | partition(pivot,cons(a,t),ord)=
    let val (left,right)=partition(pivot,t,ord)
    in let val Ord(func)=ord; in
       if func(a,pivot)=true then (cons(a,left),right)
                             else (left, cons(a,right))
                             end
                             end;

(*puts all the bigger elements after the smaller ones*)
fun attach(nil,b)=b
  | attach(cons(a,nil),b:'a list)=cons(a,b)
  | attach(cons(a,t),b: 'a list)=cons(a,attach(t,b));

(*quicksort*)
fun quicksort(nil,ord:'a Ord)=nil
  | quicksort(cons(a,nil),ord:'a Ord)=cons(a,nil)
  | quicksort(cons(h,t):'a list, ord:'a Ord)=let val(left,right)=partition(h,t,ord)
                                     in attach(quicksort(left,ord),cons(h,quicksort(right,ord))) end;

val IntSmaller: int Ord = Ord ( fn(x,y)=> x<=y );

quicksort(nil,IntSmaller);
quicksort(cons(1,nil),IntSmaller);
quicksort(cons(1,cons(2,cons(3,nil))),IntSmaller);
quicksort(cons(2,cons(1,nil)),IntSmaller);
sortbubble(nil,IntSmaller);
sortbubble(cons(1,nil),IntSmaller);
sortbubble(cons(1,cons(2,cons(3,nil))),IntSmaller);
sortbubble(cons(2,cons(3, cons(1, cons(4,nil)))),IntSmaller);
