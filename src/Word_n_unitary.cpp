/**
 * Implementation of the class Word_n_unitary
 * 
 * 
 * @author Adrien GRAS
 */
#include "../include/Word_n_unitary.hpp"




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
 * Reset Carry
 */
void Word_n_unitary::resetCarry() {

    this->data = this->data & 0x00000000FFFFFFFFULL;

}


/**
 * String setter :
 * 
 * Since we can write strings that look likes hexa numbers, here is the setter.
 */
void Word_n_unitary::setData(std::string data_) {

    // Data reset
    this->data = 0x0;


    // Erasing 0x
    if (data_.size() >= 2 && data_.substr(0, 2) == "0x") {
        data_.erase(0, 2);
    }


    // Erasing all space
    data_.erase(std::remove(data_.begin(), data_.end(), ' '), data_.end());


    // Trying to convert the string into a hex number
    try {

        // Converting the <string>data_ into an understanble data
        this->data = std::stoul(data_, nullptr, 16);

    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: the string does not represent a valid number." << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error: the string represents a number out of range." << std::endl;
    }

}


/**
 * Randomize : fill the data with random 0 and 1 
 */
void Word_n_unitary::randomize() {

    // Data reset
    this->data = 0x0;


    // Generating the random data ft. Chat GPT
    std::random_device  rd;
    std::mt19937        gen(rd());
    std::uniform_int_distribution<uint32_t> dis(0, 0xFFFFFFFF);
    uint32_t            randomLow32 = static_cast<uint32_t>(dis(gen));


    // Reset the half top + randomize the half bottom
    this->data = 0x00000000FFFFFFFF & randomLow32;

}


/**
 * Display : Display the full data stored (with its carries)
 */
void Word_n_unitary::display(bool string_shape, bool endl) const {

    // Displaying with the selected shape
    if (string_shape) {

        // Display like 'data' (without 0x)
        std::cout << std::hex << std::uppercase << std::setw(8) << std::setfill('0') << (data & 0xFFFFFFFF) << std::dec;

    } else {

        // Display the unitary word with this model [upper_part] lower_part
        std::cout   << std::hex             << std::uppercase       << "[0x"    << std::setw(8)
                    << std::setfill('0')    << (data >> 32)         << "] 0x"   << std::setw(8)
                    << std::setfill('0')    << (data & 0xFFFFFFFF)  << std::dec;


        // End of line
        if (endl) {
            std::cout << std::endl;
        }

    }

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
    return Word_n_unitary(this->data + word_n_unitary_2.getWholeData());

}


/**
 * Overriding the addition :
 * 
 * The addition is trivial. The only point is that the carry is in the half top.
 */
Word_n_unitary& Word_n_unitary::operator+=(const Word_n_unitary& word_n_unitary_2) {

    // Making the actual addition
    this->data += word_n_unitary_2.getWholeData();


    // Returning the modified word
    return *this;

}


/**
 * Overriding the substraction :
 * 
 * The substraction is trivial.
 * 
 * 
 * @todo : rework the substraction (to prevent underflow)
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
 * Data instanciation with a data
 */
Word_n_unitary& Word_n_unitary::operator=(const uint32_t data_) {

    // Getting the data
    this->data = data_;


    // Returning itslef
    return *this;

}


/**
 * Data instanciation with a string
 */
Word_n_unitary& Word_n_unitary::operator=(const std::string& data_) {

    // Data reset
    this->data = 0x0;


    // Getting the data
    this->setData(data_);


    // Returning itslef
    return *this;

}


/**
 * Comparaison : internal data compraison (instead of addr compraison)
 */
bool Word_n_unitary::operator==(const Word_n_unitary& word_n_unitary_2) const {

    // Data comparaison
    if (this->getData() == word_n_unitary_2.getData()) {
        return true;
    }
    return false;

}


/**
 * Comparaison : internal data compraison (instead of addr compraison)
 */
bool Word_n_unitary::operator!=(const Word_n_unitary& word_n_unitary_2) const {

    // Data comparaison
    if (this->getData() != word_n_unitary_2.getData()) {
        return true;
    }
    return false;

}


/**
 * Comparaison : internal data compraison (instead of addr compraison)
 */
bool Word_n_unitary::operator<=(const Word_n_unitary& word_n_unitary_2) const {

    // Data comparaison
    if (this->getData() <= word_n_unitary_2.getData()) {
        return true;
    }
    return false;

}


/**
 * Comparaison : internal data compraison (instead of addr compraison)
 */
bool Word_n_unitary::operator<(const Word_n_unitary& word_n_unitary_2) const {

    // Data comparaison
    if (this->getData() < word_n_unitary_2.getData()) {
        return true;
    }
    return false;

}


/**
 * Comparaison : internal data compraison (instead of addr compraison)
 */
bool Word_n_unitary::operator>=(const Word_n_unitary& word_n_unitary_2) const {

    // Data comparaison
    if (this->getData() >= word_n_unitary_2.getData()) {
        return true;
    }
    return false;

}


/**
 * Comparaison : internal data compraison (instead of addr compraison)
 */
bool Word_n_unitary::operator>(const Word_n_unitary& word_n_unitary_2) const {

    // Data comparaison
    if (this->getData() > word_n_unitary_2.getData()) {
        return true;
    }
    return false;

}


/**
 * Comparaison : internal data compraison with direct values
 */
bool Word_n_unitary::operator==(const uint32_t data_2) const {

    // Data comparaison
    if (this->getData() == data_2) {
        return true;
    }
    return false;

}


/**
 * Comparaison : internal data compraison with direct values
 */
bool Word_n_unitary::operator!=(const uint32_t data_2) const {

    // Data comparaison
    if (this->getData() != data_2) {
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

    // Getting the actual data
    uint32_t low32 = static_cast<uint32_t>(word_n_unitary.data);


    // Sending the data to display in the stream
    os  << std::hex << std::uppercase << "0x" << std::setw(8) << std::setfill('0') << low32 << std::dec;


    // Returning the stream
    return os;
}