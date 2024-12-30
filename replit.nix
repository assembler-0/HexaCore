{ pkgs }: {
	deps = [
   pkgs.em
   pkgs.vulkan-tools
   pkgs.sudo
   pkgs.run
   pkgs.adoptopenjdk-jre-hotspot-bin-15
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