
# Word n units

This small class is a 32-bit storage that actually uses 64 bits to store the data. The sole purpose here is to create a unitary element for a larger project, 128- to 2048-bit long words.


# Feature

This unit element can be used in operations such as addition, subtraction or multiplication. Its architecture works as follows:

|upper half (bits 32 to 63)   |lower half  (bits 0 to 31)   |
|-----------------------------|-----------------------------|
|`0 by default`               |`the actual data`            |

In fact, the data is stored in the first 32 bits of memory (the lower half). The other part (the upper half) is used to store carryovers.

## Addition

Since addition for 32-bit long words works normally, there is virtually nothing to say except that the carry is stored by the element itself.

So addition is simplified because it is literally $A + B = C.$

## Substraction

At present, subtraction is not fully implemented correctly.

## Multiplication

This storage architecture considerably simplifies multiplication for large numbers.

Multiplication is the most complex operation here. This is a way of representing how multiplication works for 64-bit long binary numbers:
###
First of all, our two operands. We divide them into two parts:
|    |upper half (bits 32 to 63)   |lower half  (bits 0 to 31)   |
|----|-----------------------------|-----------------------------|
|A = |`a1`                         |`a0`                         |
|B = |`b1`                         |`b0`                         |
###
Secondly, the result of an operation between two $2^n$ numbers is a $2^{2n}$ number. In this case, we multiply two 64-bit long numbers to obtain a 128-bit long result.
###
Finally, the operation itself:
- $A * B = (a_1 * b_1) + (a_1 * b_0 + a_0 * b_1) + (a_0 * b_0)$
- $A * B = \alpha + \beta + \gamma$
###
And these three terms live in a different power of 2:
- $\alpha$ evolves between the 127th bit and 64
- $\beta$ evolves between the 95th bit and 32
- $\gamma$ evolves between the 63rd bit and 0
###
Does that sound complicated? I think it is. But in the case of the Word_n_unitary class, $a_1$ and $b_1$ are equal to 0, and therefore so are $\alpha$ and $\beta$.
###
To sum up, if we have A and B, two objects in Word_n_unitary :
- $A * B = a_0 * b_0$3
###
> Adrien GRAS, Ecole d'ingénieurs de Mines Saint Étienne
>
>I'm not the best in English, so don't judge me too harshly :)
