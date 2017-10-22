#Oana Miron
#o.miron@jacobs-university.de
#Pb2

def prin(self):
    print("The rational number is ",self.a,"/",self.b)
def gcd(x,y):
        if y==0:
            return x
        else:
            return gcd(y,x%y)
class Rational:
    def __init__(self,a,b):
        if b==0:
            raise ZeroDivisionError
        else:
            g=gcd(a,b)
            self.a=a/g
            self.b=b/g
    def __add__(self,y):
        print("Addition")
        prin(Rational(x.a*y.b+x.b*y.a,x.b*y.b))
    def __invadd__(self):
        print("Inverse addition")
        prin( Rational(-self.a,self.b))
    def __mult__(x,y):
        print("Multiplication")
        prin( Rational(x.a*y.a,x.b*y.b))
    def __invmult__(x):
        if x.a==0:
            raise ZeroDivisionError
        else:
            print("Inverse multiplication")
            prin( Rational(x.b,x.a))
x=Rational(2,3)
y=Rational(5,10)
x.__add__(y)
x.__mult__(y)
x.__invadd__()
x.__invmult__()
