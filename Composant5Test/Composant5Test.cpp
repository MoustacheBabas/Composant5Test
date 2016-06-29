// Composant5Test.cpp : définit le point d'entrée pour l'application console.
//

// composant5tests.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "bloc.h"
#include "composant5.h"
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string chainAES;

	// TEST DE BLOCKVERIFY

	Bloc a; // Bloc correct
	a.tx1.utxo[0].dest[0] = 'a';
	a.tx1.utxo[0].dest[1] = 'b';
	a.tx1.utxo[0].dest[2] = 'c';
	a.tx1.utxo[0].dest[3] = 'd';
	a.tx1.utxo[0].montant = 100;

	Bloc b; // Bloc sans valeurs

	Bloc c; // Bloc montant négatif
	c.tx1.utxo[0].dest[0] = 'a';
	c.tx1.utxo[0].dest[1] = 'b';
	c.tx1.utxo[0].dest[2] = 'c';
	c.tx1.utxo[0].dest[3] = 'd';
	c.tx1.utxo[0].montant = -100;

	blockVerify(a, chainAES); // OK.
	blockVerify(b, chainAES); // est censé afficher le message d'erreur "MISSED VALUE" car b manque de valeurs
	blockVerify(c, chainAES); // est censé afficher le message d'erreur "INVALIDE TYPE OF DATA"

	// TEST DE TRANSFERTVERIFY

	TX t1; // transaction OK
	t1.utxo[0].dest[0] = 'a';
	t1.utxo[0].dest[1] = 'b';
	t1.utxo[0].dest[2] = 'c';
	t1.utxo[0].dest[3] = 'd';
	t1.utxo[0].montant = 100;

	TX t2; // transaction manquant d'une valeur
	t2.utxo[0].dest[0];
	t2.utxo[0].dest[1] = 'b';
	t2.utxo[0].dest[2] = 'c';
	t2.utxo[0].dest[3] = 'd';
	t2.utxo[0].montant = 100;

	TX t3; // transaction montant négatif
	t3.utxo[0].dest[0] = 'a';
	t3.utxo[0].dest[1] = 'b';
	t3.utxo[0].dest[2] = 'c';
	t3.utxo[0].dest[3] = 'd';
	t3.utxo[0].montant = -100;

	transfertVerify(t1, chainAES); // OK.
	transfertVerify(t2, chainAES); // est censé afficher le message d'erreur "MISSED VALUE" car b manque de valeurs
	transfertVerify(t3, chainAES); // est censé afficher le message d'erreur "INVALIDE TYPE OF DATA"

	return 0;
}
