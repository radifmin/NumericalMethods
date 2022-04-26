#pragma once
#include <iostream>
#include <array>

#define DEBUG_LIB
// NumMethods
#include "NumMethods/LinearEquations/Config.h";
#include "NumMethods/LinearEquations/MatrixLinearCoefs.h"
#include "NumMethods/LinearEquations/IterativeInterface.h"
#include "NumMethods/LinearEquations/Iterative/Thomas.h"
#include "NumMethods/LinearEquations/Iterative/Seidel.h"
#include "NumMethods/LinearEquations/Iterative/Jacobi.h"
#include "NumMethods/LinearEquations/Iterative/UpRelaxation.h"
#include"NumMethods/LinearEquations/Iterative/DownRelaxtion.h"
#include "NumMethods/LinearEquations/Iterative/GreatDescent.h"

//Kursach
#include"Kursach/Config2.0.h"
#include"Kursach/MainWork/testExercise.h"
#include"Kursach/TestMethods/testsKursach.h"