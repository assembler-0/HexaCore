{ pkgs }: {
	deps = [
   pkgs.nasm
   pkgs.iproute
   pkgs.pciutils
   pkgs.neofetch
   pkgs.wget
   pkgs.micro
   pkgs.nano
		pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}