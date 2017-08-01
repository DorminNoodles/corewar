***** Wesh les gros *****

Je fais un README.md pour communiquer les infos INDISPENSABLES pour avancer.

A la racine d'"asm", on compile tous les *.c et *.h, avec la libft (j'ai pris la mienne parce qu'elle compile mon printf, c'est un detail, on changera ca plus tard).
Le binaire s'execute avec un .s dans le dossier "tests".

ATM :
	Je suis entrain de faire un compteur d'octets fonctionnel. Pour le moment, je pars du principe que ce qui est envoye est valide.
FOR :
	Le compilateur va d'abord lire une premiere fois le fichier afin de recuperer les labels et leur position en octets a partir de l'octet 0 (qui est le debut des instructions asm). Pour le moment, ce qui est au dessus des instructions en asm est ignore, afin de ne pas trop en chier pour verifier les sorties en hexa.

SOON:
	Lorsque le compteur sera fonctionnel, il est, pour le moment, prevu de stocker les noms des labels dans une liste chainee, qui ressemblera a un truc comme ca:

	typedef struct s_labs
	{
		char	*name;
		int		*pos;
		void	*next;
	}			t_labs

	Je ne vois pas de raison d'avoir une autre structure pour l'asm, ni meme de stocker d'autres donnees. On ne va rien stocker d'autre que le nom des labels et leurs positions.
	Le compilateur va lire, ligne par ligne, le .s et convertir les instructions en char, short et int, selon ce que l'on converti.

RAPPEL:
	OPCODE: 1 octet.
	OCP : 1 octet.
	REGISTRE : 1 octet.
	INDEX : 2 octets.
	DIRECT : 2 octets pour les adresses memoires (Instructions zjmp, ldi, sti, fork, ldi, lfork)
			 4 octets pour les entiers (instructions live, ld, and, or, xor, lld)

VDM:
	En ce qui concerne le check, il pourrait intervenir a chaque ligne pendant le comptage des octets, au premier passage du gnl et serait ignore la seconde fois, lors de la convertion de l'asm.
	Pour l'ecriture, j'imagine qu'a la suite du comptage d'octets et de la recuperation des labels, on pourra creer le fichier, et ft_put/char/str_fd directement dedans.
	Je ne suis pas encore certain de tout cela. Toute remarque est bienvienue a ce sujet.
