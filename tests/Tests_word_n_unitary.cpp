/**
 * Test for Word_n_unitary
 * 
 * 
 * Test vector : generated using python
 * 
 * @author AdrienG
 */
#include <iostream>
#include "../include/Word_n_unitary.hpp"




// Signatures
int test_Word_n_unitary_addition();
int test_Word_n_unitary_substraction();
int test_Word_n_unitary_multiplication();




/**
 * All test execution
 */
int main() {

    // Test variable
    int test = 0;


    // Test start
    std::cout << "Test(Word_n_unitary) : START" << std::endl;
    std::cout << "\n\n" << std::endl;


    // Display test
    Word_n_unitary word = Word_n_unitary(0x1AFFFF0000ULL);
    std::cout << "Test(Word_n_unitary) : Cout               -> " << word << std::endl;
    std::cout << "Test(Word_n_unitary) : DISPLAY            -> ";
    word.display();


    // Randomizer test
    word.randomize();
    std::cout << "Test(Word_n_unitary) : RANDOMIZE          -> ";
    word.display();


    // Reset test
    word.reset();
    if (word.getData() != 0x0) {
        test += 1;
        std::cout << "Test(Word_n_unitary) : RESET              -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n_unitary) : RESET              -> PASSED" << std::endl;
    }


    // Carry test
    word.setData(0x1AFFFF0000ULL);
    if (word.getCarry() != 0x0000001A) {
        test += 1;
        std::cout << "Test(Word_n_unitary) : CARRY              -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n_unitary) : CARRY              -> PASSED" << std::endl;
    }


    // Carry reset test
    word.resetCarry();
    if (word.getCarry() != 0x00000000) {
        test += 1;
        std::cout << "Test(Word_n_unitary) : CARRY RESET        -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n_unitary) : CARRY RESET        -> PASSED" << std::endl;
    }


    // String setter test
    word.setData("0x1AFFFFULL");
    if (word.getData() != 0x1AFFFFULL) {
        test += 1;
        std::cout << "Test(Word_n_unitary) : STRING SETTER      -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n_unitary) : STRING SETTER      -> PASSED" << std::endl;
    }


    // Data instanciation with = uint test
    word = 0x458FFULL;
    if (word.getData() != 0x458FFULL) {
        test += 1;
        std::cout << "Test(Word_n_unitary) : OP (VAR = UINT)    -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n_unitary) : OP (VAR = UINT)    -> PASSED" << std::endl;
    }


    // Data instanciation with = string test
    word = "0x477893B";
    if (word.getData() != 0x477893B) {
        test += 1;
        std::cout << "Test(Word_n_unitary) : OP (VAR = STRING)  -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n_unitary) : OP (VAR = STRING)  -> PASSED" << std::endl;
    }


    // Data comparaison with == uint test
    word = 0x458FFULL;
    if ((word == 0x458FFULL) != true) {
        test += 1;
        std::cout << "Test(Word_n_unitary) : OP (VAR == UINT)   -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n_unitary) : OP (VAR == UINT)   -> PASSED" << std::endl;
    }


    // Data comparaison with == string test
    Word_n_unitary word_2 = Word_n_unitary(0x477893B);
    word = 0x477893B;
    if ((word == word_2) != true) {
        test += 1;
        std::cout << "Test(Word_n_unitary) : OP (VAR1 == VAR2)  -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n_unitary) : OP (VAR1 == VAR2)  -> PASSED" << std::endl;
    }


    // Addition
    int addition = test_Word_n_unitary_addition();
    if (addition == 1) {
        std::cout << "Test(Word_n_unitary) : ADDITION           -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n_unitary) : ADDITION           -> PASSED" << std::endl;
    }
    test += addition;


    // Substraction
    int substaction = test_Word_n_unitary_substraction();
    if (substaction == 1) {
        std::cout << "Test(Word_n_unitary) : SUBSTRACTION       -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n_unitary) : SUBSTRACTION       -> PASSED" << std::endl;
    }
    test += substaction;


    // Addition
    int multiplication = test_Word_n_unitary_multiplication();
    if (multiplication == 1) {
        std::cout << "Test(Word_n_unitary) : MULTIPLICATION     -> FAILED" << std::endl;
    } else {
        std::cout << "Test(Word_n_unitary) : MULTIPLICATION     -> PASSED" << std::endl;
    }
    test += multiplication;


    // Program end
    std::cout << "\n\n" << std::endl;
    if (test == 0) {
        std::cout << "Test(Word_n_unitary) : PASSED" << std::endl;
        return 0;
    }
    std::cout << "Test(Word_n_unitary) : FAILED" << std::endl;
    return 1;

}




/**
 * Addition tests
 */
int test_Word_n_unitary_addition() {

    // Test variables
    Word_n_unitary word_n_unitary_1 = Word_n_unitary();
    Word_n_unitary word_n_unitary_2 = Word_n_unitary();
    Word_n_unitary word_n_unitary_3 = Word_n_unitary();


    /**
     * Calculation 1 :
     * 
     * A = 0xF1DFD08D
     * B = 0x5A467FBE
     * 
     * C = A + B = 0x1 4C26504B
     */
    word_n_unitary_1 = 0xF1DFD08D;
    word_n_unitary_2 = 0x5A467FBE;
    word_n_unitary_3 = word_n_unitary_1 + word_n_unitary_2;


    // Test + reset
    if (word_n_unitary_3 != 0x14C26504B) {return 1;}
    word_n_unitary_3 = 0x0;




    /**
     * Calculation 2 :
     * 
     * A = 0x5D3BCC74
     * B = 0x674B2834
     * 
     * C = A + B = 0xC486F4A8
     */
    word_n_unitary_1 = 0x5D3BCC74;
    word_n_unitary_3 = 0x674B2834;
    word_n_unitary_3 += word_n_unitary_1;


    // Test + reset
    if (word_n_unitary_3 != 0xC486F4A8) {return 1;}
    word_n_unitary_3 = 0x0;




    /**
     * Calculation 3 :
     * 
     * A = 0x77A248B4
     * B = 0x2657693D
     * 
     * C = A + B = 0x9DF9B1F1
     */
    word_n_unitary_1 = 0x77A248B4;
    word_n_unitary_2 = 0x2657693D;
    word_n_unitary_3 = word_n_unitary_1 + word_n_unitary_2;


    // Test + reset
    if (word_n_unitary_3 != 0x9DF9B1F1) {return 1;}
    word_n_unitary_3 = 0x0;





    // End of test
    return 0;

};




/**
 * Substraction tests
 */
int test_Word_n_unitary_substraction() {

    // Test variables
    Word_n_unitary word_n_unitary_1 = Word_n_unitary();
    Word_n_unitary word_n_unitary_2 = Word_n_unitary();
    Word_n_unitary word_n_unitary_3 = Word_n_unitary();


    /**
     * Calculation 1 :
     * 
     * A = 0x94349C86
     * B = 0x62E95794
     * 
     * C = A - B = 0x314B44F2
     */
    word_n_unitary_1 = 0x94349C86;
    word_n_unitary_2 = 0x62E95794;
    word_n_unitary_3 = word_n_unitary_1 - word_n_unitary_2;


    // Test + reset
    if (word_n_unitary_3 != 0x314B44F2) {return 1;}
    word_n_unitary_3 = 0x0;




    /**
     * Calculation 2 :
     * 
     * A = 0xBF6E8AF5
     * B = 0x5902142E
     * 
     * C = A - B = 0x666C76C7
     */
    word_n_unitary_1 = 0xBF6E8AF5;
    word_n_unitary_2 = 0x5902142E;
    word_n_unitary_3 = word_n_unitary_1 - word_n_unitary_2;


    // Test + reset
    if (word_n_unitary_3 != 0x666C76C7) {return 1;}
    word_n_unitary_3 = 0x0;




    /**
     * Calculation 3 :
     * 
     * A = 0x9284A957
     * B = 0x51D30D2A
     * 
     * C = A - B = 0x40B19C2D
     */
    word_n_unitary_1 = 0x9284A957;
    word_n_unitary_2 = 0x51D30D2A;
    word_n_unitary_3 = word_n_unitary_1 - word_n_unitary_2;


    // Test + reset
    if (word_n_unitary_3 != 0x40B19C2D) {return 1;}
    word_n_unitary_3 = 0x0;




    // End of test
    return 0;

};




/**
 * Multiplication tests
 */
int test_Word_n_unitary_multiplication() {

    // Test variables
    Word_n_unitary word_n_unitary_1 = Word_n_unitary();
    Word_n_unitary word_n_unitary_2 = Word_n_unitary();
    Word_n_unitary word_n_unitary_3 = Word_n_unitary();


    /**
     * Calculation 1 :
     * 
     * A = 0xFEDEAB26
     * B = 0x892B5FD5
     * 
     * C = A * B = 0x88905866 C629809E
     */
    word_n_unitary_1 = 0xFEDEAB26;
    word_n_unitary_2 = 0x892B5FD5;
    word_n_unitary_3 = word_n_unitary_1 * word_n_unitary_2;


    // Test + reset
    if (word_n_unitary_3 != 0x88905866C629809E) {return 1;}
    word_n_unitary_3 = 0x0;




    /**
     * Calculation 2 :
     * 
     * A = 0xE0F017AE
     * B = 0x878B3C5E
     * 
     * C = A * B = 0x7718F3E4 7B2F79E4
     */
    word_n_unitary_1 = 0xE0F017AE;
    word_n_unitary_2 = 0x878B3C5E;
    word_n_unitary_3 = word_n_unitary_1 * word_n_unitary_2;


    // Test + reset
    if (word_n_unitary_3 != 0x7718F3E47B2F79E4) {return 1;}
    word_n_unitary_3 = 0x0;




    /**
     * Calculation 3 :
     * 
     * A = 0x79FAAA1A
     * B = 0xD5B183E6
     * 
     * C = A + B = 0x65D224B0 1A3A215C
     */
    word_n_unitary_1 = 0x79FAAA1A;
    word_n_unitary_2 = 0xD5B183E6;
    word_n_unitary_3 = word_n_unitary_1 * word_n_unitary_2;


    // Test + reset
    if (word_n_unitary_3 != 0x65D224B01A3A215C) {return 1;}
    word_n_unitary_3 = 0x0;




    // End of test
    return 0;

}
