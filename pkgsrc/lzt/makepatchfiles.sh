set -e
make clean
make patch
rm -rf patches
mkpatches
rm -f patches/*.orig
make mps
