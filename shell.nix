{ pkgs ? import <nixpkgs> {} }:
  pkgs.mkShell {
    buildInputs = [
                    pkgs.qt6.full
                    pkgs.qtcreator
                  ];
}