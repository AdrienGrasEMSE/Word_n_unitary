#include "../include/Word_n_unitary.hpp"
#include <iomanip>

/**
 * ================================================================================================
 * Constructors and Destructors
 * ================================================================================================
 */

/**
 * Default Constructor : Initialize to zero
 */
Word_n_unitary::Word_n_unitary() {

    // Filling up the data with zeros
    data = 0x0;

}


/**
 * Constructor with direct instanciation 
 */
Word_n_unitary::Word_n_unitary(uint64_t data_) {

    // Filling up the data
    this->data = data_;

}


/**
 * Destructor
 * 
 */
Word_n_unitary::~Word_n_unitary() {
    // Nothing to do here
}




/**
 * ================================================================================================
 * Utilities
 * ================================================================================================
 */

/**
 * Randomize : fill the data with random 0 and 1 
 */
void Word_n_unitary::randomize() {

    // Generating the random data ft. Chat GPT
    std::random_device  rd;
    std::mt19937        gen(rd());
    std::uniform_int_distribution<uint32_t> dis(0, 0xFFFFFFFF);
    uint32_t            randomLow32 = static_cast<uint32_t>(dis(gen));


    // Reset the half top + randomize the half bottom
    this->data = 0x00000000FFFFFFFF && randomLow32;

}




/**
 * ================================================================================================
 * Operators
 * ================================================================================================
 */

/**
 * Overriding the addition :
 * 
 * The addition is trivial. The only point is that the carry is in the half top.
 */
Word_n_unitary Word_n_unitary::operator+(const Word_n_unitary& word_n_unitary_2) const {

    // Returning the sum
    return Word_n_unitary(this->data + word_n_unitary_2.getData());
}


/**
 * Overriding the substraction :
 * 
 * The substraction is trivial.
 */
Word_n_unitary Word_n_unitary::operator-(const Word_n_unitary& word_n_unitary_2) const {

    // Returning the substraction
    return Word_n_unitary(this->data - word_n_unitary_2.getData());
}


/**
 * Overriding the multiplication :
 * 
 * We multiply two word_units using their properties :
 * 
 * A = [a1, a0]
 * B = [b1, b0]
 * 
 * 
 *  bit      128    96      64      32      0
 *           |      |       |       |       |
 *  A * B =                 [a1,    a0      ]
 *          *               [b1,    b0      ]
 *        =
 *                          [a0     * b0    ]
 *        +         [a1     * b0    ]
 *        +         [b1     * a0    ]
 *        + [a1     * b1    ]
 * 
 * 
 * But each 64bit word_units only use its 32 lower bits to store data, and so :
 *  a1 = 0
 *  b1 = 0
 * 
 * Finally :
 *      => So A * B = [a0 * b0]
 */
Word_n_unitary Word_n_unitary::operator*(const Word_n_unitary& word_n_unitary_2) const {

    // Returning the product
    return Word_n_unitary((this->data & 0xFFFFFFFF) * (word_n_unitary_2.getData() & 0xFFFFFFFF));
}


/**
 * Comparaison : internal data compraison (instead of addr compraison)
 */
bool Word_n_unitary::operator!=(const Word_n_unitary& word_n_unitary_2) const {

    // Data comparaison
    if (this->data != word_n_unitary_2.getData()) {
        return true;
    }
    return false;

}


/**
 * Comparaison : internal data compraison with direct values
 */
bool Word_n_unitary::operator!=(const u_int64_t data_2) const {

    // Data comparaison
    if (this->data != data_2) {
        return true;
    }
    return false;

}


/**
 * Overriding Cout :
 * 
 * Display only the usable data (each 32bit long lower part of word_units)
 */
std::ostream& operator<<(std::ostream& os, const Word_n_unitary& word_n_unitary) {

    // Configure output stream to make it display uppercase hexa
    os << std::hex << std::uppercase;


    // Getting the actual data
    uint32_t low32 = static_cast<uint32_t>(word_n_unitary.data);


    // Sending the data to display in the stream
    os << low32 << std::endl;


    // Reseting the output stream (to not disturb other other display)
    os << std::dec << std::endl;


    // Returning the stream
    return os;
}