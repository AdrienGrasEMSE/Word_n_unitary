#ifndef WORD_N_UNITARY
#define WORD_N_UNITARY



// Imports
#include <iostream>             // For the std::cout override
#include <stdint.h>             // For the data format : uint64_t
#include <random>               // For the randomize method


/**
 * Class Word_n_unitary :
 * 
 * Class which store 32 bit data, in 64 bit long variable, for good compatibility
 * with addition or multiplication.
 * 
 * 
 * @author Adrien GRAS
 */
class Word_n_unitary {
private:

    /**
     * The data itself
     * 
     * 
     * Only the half bottom is considered.
     * The half top is used for operation, to store caries or the half top result.
     * 
     *          63                  31                  0
     *          |                   |                   |
     * Data :  [  zeros by default  .    actual data     ]
     * 
     */
    uint64_t data;


public:

    // Constructors
    Word_n_unitary();
    Word_n_unitary(uint64_t data);


    // Destructor
    ~Word_n_unitary();


    // Bloc setter and getter
    void            setData(uint64_t data_) {this->data = data_;}
    uint64_t        getData() const         {return this->data;}


    // Fill a random value in the data
    void            randomize();


    // Overriding operators
    Word_n_unitary  operator+   (const Word_n_unitary& word_n_unitary_2)    const;
    Word_n_unitary& operator+=  (const Word_n_unitary& word_n_unitary_2);
    Word_n_unitary  operator-   (const Word_n_unitary& word_n_unitary_2)    const;
    Word_n_unitary  operator*   (const Word_n_unitary& word_n_unitary_2)    const;
    bool            operator!=  (const Word_n_unitary& word_n_unitary_2)    const;
    bool            operator!=  (const uint64_t data_2)                     const;


    // Overriding std::cout for display
    friend std::ostream& operator<<(std::ostream& os, const Word_n_unitary& word_n_unitary);

};


#endif // WORD_N_UNITARY




