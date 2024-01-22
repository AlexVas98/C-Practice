﻿/*
Online εξέταση του μαθήματος ΠΡΟΓΡΑΜΜΑΤΙΣΜΟΣ ΜΕ C++.
Επαναληπτική εξεταστική Σεπτεμβρίου 2020.
*/

#include "Rand.h"
#include "SparseMatrix.h"
#include <cstdio>
#include <iostream>
#include <string>

/*
Ένας "αραιός πίνακας" προγραμματιστικά είναι ένας πίνακας που δε δηλώνεται και γεμίζεται
με τιμές σε συμπαγή, συνεκτική μορφή, αλλά προσδιορίζονται μεμονωμένα εκείνες οι θέσεις
του που περιέχουν μια "μη μηδενική" τιμή. Αυτό έχει ως άμεση συνέπεια ότι σε αντίθεση
με έναν τυπικό συμπαγή πίνακα για τον οποίο στη μνήμη κρατάμε όλα τα στοιχεία, σε έναν
αραιό πίνακα, φυλάμε μόνο τα μη μηδενικά στοιχεία, σε κατάλληλες δομές.

Για παράδειγμα, μπορώ να έχω ένα διαγώνιο πίνακα 100Χ100 θέσεων. Σε αυτόν τον πίνακα,
όλες οι τιμές έξω από τη διαγώνιό του είναι μηδενικές, άρα χρειάζεται να προσδιορίσω και
να φυλάω μόνο τις 100 τιμές πάνω στη διαγώνιο. Έτσι, αντί να εισάγω 10000 στοιχεία και
αντίστοιχα να ξοδεύω μνήμη για αυτά, προσδιορίζω πλήρως τον πίνακα παρέχοντας και
διατηρώντας μόνο τα 100 που χρειάζομαι. Αντίστοιχα, αν θέλω να φτιάξω έναν πίνακα
Α 30Χ20 όπου μόνο τα στοιχεία α11 και α23 έχουν μη μηδενικές τιμές, προσδιορίζω
προγραμματιστικά και φυλάω μόνο αυτά τα 2 στοιχεία.

Στο διαγώνισμα, καλείστε να υλοποιήσετε μια templated κλάση SparseMatrix<T>, η οποία
μοντελοποιεί έναν αραιό πίνακα και υλοποιεί τη λειτουργικότητά του. Η κλάση αυτή θα
πρέπει να υπακούει στη διεπαφή SparseMatrixTraits<T> που βρίσκεται στο αρχείο
SparseMatrixTraits.h και επομένως, θα πρέπει να την κληρονομεί και να υλοποιεί τις
μεθόδους που δηλώνονται εκεί. Τη δήλωση KAI υλοποίηση της SparseMatrix<T> θα
πρέπει να την κάνετε μέσα σε ένα αρχείο με όνομα SparseMatrix.h, το οποίο ήδη
ενσωματώνεται στο αρχείο exam.cpp που αποτελεί το κύριο πρόγραμμα. Είστε
ελεύθεροι να την υλοποιήσετε με όποιον τρόπο κρίνετε πιο αποδοτικό, συστίνεται
παρόλα αυτά η χρήση έτοιμων δομών δεδομένων της STL, για δική σας διεκόλυνση.

Για να εκτελεστεί το τελικό πρόγραμμα, πρέπει να του περάσετε σαν παράμετρο
(command line argument) τον αριθμό μητρώου σας (π.χ. 3100001, ΧΩΡΙΣ το 'p').
Η έξοδος του προγράμματος (δηλαδή αυτό που εκτυπώνει) αποτελεί την απάντηση
στο ερώτημα 2.

Προσοχή: ΔΕΝ ΠΡΕΠΕΙ ΝΑ ΜΕΤΑΒΑΛΕΤΕ ΚΑΝΕΝΑ ΑΡΧΕΙΟ ΑΠΟ ΑΥΤΑ ΠΟΥ ΣΑΣ ΔΙΝΟΝΤΑΙ. Γράφετε
το κώδικά σας στο αρχείο SparseMatrix.h και κάνετε compile το πρόγραμμα έτσι ώστε ο
κώδικας που υπάρχει μέσα στις 3 συναρτήσεις Test1,2,3 που καλούνται από τη main να
δουλεύει. Κατά την ανάπτυξη του κώδικά σας, μπορείτε να βάλετε σε σχόλια όποια από
αυτές θέλετε, μέχρι να είναι σε θέση να εκτελεστούν. Προφανώς, τοπικά μπορείτε να
πειραματιστείτε με τον κώδικά σας όπως επιθυμείτε, αλλά για τη βαθμολόγηση δε θα
ληφθεί υπόψη καμία παρέμβαση στα περιεχόμενα των αρχείων που σας δίνονται έτοιμα.
Αν κάποια από τις Test1..3 συναρτήσεις δε δουλεύει όταν ολοκληρώσετε τον κώδικά σας,
αφήστε τη σε σχόλια, καθώς θα χρειαστεί να καταγράψετε την έξοδο της εκτέλεσης του
προγράμματος.

Ενδεικτική έξοδος του προγράμματος για ΑΜ 3111111:

-------------------------------------------------------------

Test 1: Simple sparse matrix test.
Set up a 3X3 sparse matrix and query ALL of its elements.

1 0 2
0 0 0
3 0 4

-------------------------------------------------------------

Test 2: Random Matrix.
Set up and compactly display a sparse array of 20 elements.


(1720, 776): -0.0782189
(452, 596): -0.468246
(1335, 548): -0.994873
(93, 448): -0.223609
(957, 1647): 0.543443
(559, 1387): 0.714591
(1865, 490): 0.203772
(587, 1139): 0.218177
(168, 99): 0.939451
(1895, 1497): -0.687979
(682, 902): 0.651662
(1112, 1461): 0.0775476
(1116, 520): -0.930296
(772, 686): -0.809381
(1235, 971): 0.896847
(806, 9): 0.230873
(1241, 1445): 0.269143
(1675, 864): -0.354961
(821, 957): 0.258217
(427, 1785): 0.572497
-------------------------------------------------------------

Test 3: Test == operator.

Created a random sparse matrix A.
Copying A to matrix B.
Matrices A and B should be equal: PASS.
Changing random element in B.
Matrices A and B should not be equal: PASS.
Restoring B, changing random element in A.
Matrices A and B should not be equal: PASS.


Ζητούμενο 1. Υλοποιήστε και ανεβάστε το αρχείο SparseMatrix.h ΜΟΝΟ, ως ένα από τα 2 αρχεία
που σας ζητούνται. ΜΗΝ ανεβάσετε κάποιο zip αρχείο με όλο τον κώδικά σας: Δε θα βαθμολογηθεί.

Ζητούμενο 2. Αντιγράψτε και ανεβάστε την έξοδο του προγράμματος, όταν τελικά τρέξει, ως το
δεύτερο από τα 2 αρχεία που σας ζητούνται να ανεβάσετε. Το αρχείο αυτό μπορεί να είναι είτε
αρχείο κειμένου (έχοντας κάνει copy - paste την έξοδο ή ανακατευθύνοντας την έξοδο του προγράμματος
από τη γραμμή εντολών με ">") είτε screenshot του παραθύρου εξόδου. Σε κάθε περίπτωση πρέπει να
έμφανίζεται οολόκληρη η έξοδος.

Προσοχή: η έξοδός του εξαρτάται από τον αριθμό μητρώου που έχετε περάσει
και η απάντηση θα επαληθευτεί με το δικό σας αριθμό μητρώου κατά τη βαθμολόγηση.
*/

void Test1(int seed) {
    std::cout << "-------------------------------------------------------------\n";
    std::cout << "\nTest 1: Simple sparse matrix test.\n";
    std::cout << "Set up a 3X3 sparse matrix and query ALL of its elements.\n\n";

    SetRandomSeed(seed);

    SparseMatrix<int> A;
    A({0, 0}) = 1;
    A({0, 2}) = 2;
    A({2, 0}) = 3;
    A({2, 2}) = 4;

    for (unsigned int i = 0; i < 3; i++) {
        for (unsigned int j = 0; j < 3; j++) {
            std::cout << A({i, j}) << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";
}

void Test2(int seed) {
    std::cout << "-------------------------------------------------------------\n";
    std::cout << "\nTest 2: Random Matrix.\n";
    std::cout << "Set up and compactly display a sparse array of 20 elements.\n\n";

    SetRandomSeed(seed);

    SparseMatrix<float> A;
    for (int i = 0; i < 20; i++) {
        Coordinates pos = {RandomInteger<2000>(), RandomInteger<2000>()};
        A(pos) = RandomFloat();
    }

    A.print();
    std::cout << "\n";
}

void Test3(int seed) {
    std::cout << "-------------------------------------------------------------\n";
    SetRandomSeed(seed);
    const unsigned int sz = 40;

    std::cout << "\nTest 3: Test == operator.\n";

    SparseMatrix<double> A;

    for (unsigned int i = 0; i < sz; i++) {
        unsigned int offset = RandomInteger<sz * sz>();
        A({offset / sz, offset % sz}) = 1;
    }

    std::cout << "\nCreated a random sparse matrix A.\n";
    std::cout << "Copying A to matrix B.\n";

    SparseMatrix<double> B = A;

    std::cout << "Matrices A and B should be equal: " << (A == B ? "PASS" : "FAIL") << ".\n";
    std::cout << "Changing random element in B.\n";

    B({RandomInteger<39>(), RandomInteger<39>()}) = 2;

    std::cout << "Matrices A and B should not be equal: " << (A == B ? "FAIL" : "PASS") << ".\n";
    std::cout << "Restoring B, changing random element in A.\n";

    B = A;
    A({RandomInteger<39>(), RandomInteger<39>()}) = 0;

    std::cout << "Matrices A and B should not be equal: " << (A == B ? "FAIL" : "PASS") << ".\n";
    std::cout << "\n";
}

int main(int argc, char** argv) {
    // if (argc < 2)
    // {
    // 	std::cerr << "Please provide your student number (no leading letter) as an argument. E.g. 3015422\n";
    // 	exit(-1);
    // }
    // int seed = atoi(argv[1]);

    int seed = 12312;

    Test1(seed);
    Test2(seed);
    Test3(seed);

    return 0;
}
