/**
 * \file Splitter.hpp
 *
 * \author Panagiotis Fotopoulos
 *
 * \copyright Copyright 2018 NCSR Demokritos Greece \n
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. \n
 */

#ifndef SPLITTER_H
#define SPLITTER_H


// system headers
#include <vector>

// project headers
#include "Atom.hpp"
#include "Payload.hpp"

// defines
#define ATOMSIZE_DEFAULT_VALUE 3


using namespace std;


/**
 * \Class An abstract class working as an interface that describes a Splitter, a class that can split a payload into Atoms.\n
 * Usage: Every proximity graph holds a Splitter. The graph can order the Splitter to split its payload into atoms and create a node for every atom created.
 * \note No payload defined variable in this abstract superclass. Sub-classes must define their own payload variable, according to the type they are going to work with.
 */
template <typename PayloadType, typename AtomType>
class Splitter
{
    public:
        /**
         * Default constructor. atomSize set to ATOMSIZE_DEFAULT_VALUE.
         */
        Splitter(){ atomSize = ATOMSIZE_DEFAULT_VALUE; }



        /**
         * Constructor that initializes atomSize.
         * \param atomSizeValue The new value for the atomSize variable.
         */
        Splitter(unsigned int atomSizeValue){ atomSize = atomSizeValue; }



        /** Mutator for atomSize variable.
         * \param setValue The new atom size that the Splitter will split its payload to.
         */
        void setAtomSize(unsigned int newAtomSizeValue){ this->atomSize = newAtomSizeValue; }



        /** Accessor for atomSize variable.
         * \return Current atom size that the Splitter will split its payload to.
         */
        unsigned int getAtomSize(){ return atomSize; }



        /**
         * Splits the payload to Atoms, and returns the result in a vector.
         * \return A vector with the Atoms to which the payload was split.
         */
        virtual std::vector<Atom<AtomType>> splitPayloadToAtoms(Payload<PayloadType> *payloadToSplit) = 0;



    protected:
        /** \var atomSize
         * The length of each atom.\n
         * Defaults to ATOMSIZE_DEFAULT_VALUE.
         */
        unsigned int atomSize;
};


#endif // SPLITTER_H
