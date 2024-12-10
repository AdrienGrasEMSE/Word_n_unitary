
# Word n units

This little class is a 32 bit storage which actually use 64 bit to store data. The only goal here, is to create unitary element for a bigger project, 128 to 2048bit long words.


# Feature

This unitary element can be used in operation like addition, substraction or multiplication. Its architecture works like that :

|half-top (bits 32 to 63)       |half-bottom (bits 0 to 31)   |
|-------------------------------|-----------------------------|
|`0 by default`                 |`the actual data`            |

In fact, the data is store in the first 32bit of the storage (the half bottom). The other part (the half top), is used to store carries.

## Addition

Since the addition for 32bit long words works normally, there is pretty much nothing to say, except that the carry is stored by the element itself.

And so it simplifies the addition because it is literally $A + B = C.$

## Substraction

Currently it is not completely imlpemented properly.

## Multiplication

This storage architecture simplify a lot the multiplication for bigger numbers.

The multiplication is the most complex operation here. This is a way to reprensent how the multiplication works for 64bit long binary numbers :
###
First, our two operands. We divide them into two parts :
|    |half-top (bits 32 to 63)     |half-bottom (bits 0 to 31)   |
|----|-----------------------------|-----------------------------|
|A = |`a1`                         |`a0`                         |
|B = |`b1`                         |`b0`                         |
###
Second, the result of an operation between two $2^n$ numbers is a $2^2n$ number. In this case, we multiply two 64bit long numbers, and we got a 128bit long result.
###
Finnally, the operation itslef :
$A*B=(a_1*b_1)+(a_1*b_0+a_0*b_1)+(a_0*b_0)$
$A*B=\alpha+\beta+\gamma$
###
And these three terme live in a different power of 2 :
- $\alpha$ evolve between the 127th bit and the 64
- $\beta$ evolve between the 95th bit and the 32
- $\gamma$ evolve between the 63th bit and the 0
###
Seems complicated ? I think so. But in the case of the class Word_n_unitary, $a_1$ and $b_1$ equals 0, and so $\alpha$ and $\beta$ too.
###
In a nutshell, if we have A and B, two objet from Word_n_unitary :
$A*B=a_0*b_0$

