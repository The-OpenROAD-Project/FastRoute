////////////////////////////////////////////////////////////////////////////////
// Authors: Vitor Bandeira, Eder Matheus Monteiro e Isadora
// Oliveira
//          (Advisor: Ricardo Reis)
//
// BSD 3-Clause License
//
// Copyright (c) 2019, Federal University of Rio Grande do Sul (UFRGS)
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// * Neither the name of the copyright holder nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
////////////////////////////////////////////////////////////////////////////////

#ifndef __BOX_H_
#define __BOX_H_

#include <algorithm>
#include <limits>
#include "Coordinate.h"

namespace FastRoute {

class Box {
private:
        Coordinate _lowerBound;
        Coordinate _upperBound;
        int _layer;

public:
        Box() : _lowerBound(Coordinate(0, 0)), _upperBound(Coordinate(0, 0)), 
                _layer(-1) {};

        Box(const Coordinate& lowerBound, const Coordinate& upperBound,
            const int layer)
            : _lowerBound(lowerBound), _upperBound(upperBound), _layer(layer) {}
        
        Box(const DBU lowerX, const DBU lowerY, const DBU upperX, const DBU upperY,
            const int layer)
            : _lowerBound(Coordinate(lowerX, lowerY)),
              _upperBound(Coordinate(upperX, upperY)),
              _layer(layer) {}

        Coordinate getLowerBound() const { return _lowerBound; }
        Coordinate getUpperBound() const { return _upperBound; }
        int getLayer() const { return _layer; }

        DBU getHalfPerimeter();
        Coordinate getMiddle();
        
        bool overlap(Box box);
};

}

#endif /* __BOX_H_ */
