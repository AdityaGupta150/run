# Maintainer: Aditya Gupta <ag15035 at gmail dot com>
pkgname=run-git
pkgver=r3.91db087
pkgrel=1
pkgdesc="A simpler shorter way to Compile AND Run a .cpp file"
arch=('x86_64')
url="https://github.com/adi-g15/run"
license=('Unlicense')
depends=('gcc')
makedepends=('git')
provides=("${pkgname%-git}")
conflicts=("${pkgname%-git}")
source=('git+https://github.com/adi-g15/run.git')
md5sums=('SKIP')

pkgver() {
	cd "$srcdir/${pkgname%-git}"

	printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

build() {
	cd "$srcdir/${pkgname%-git}"
	make
}

package() {
	cd "$srcdir/${pkgname%-git}"
	DESTDIR="$pkgdir/" make install
}
