# Maintainer: Eliott Wanner <eliott.wanner@gmail.com>
pkgname='tclock'
pkgver=1
pkgrel=1
pkgdesc="ncurses-based terminal clock written in C"
arch=('x86_64' 'aarch64' 'armv7h' 'i686')
url="https://gitlab.com/eliott.wnr/tclock"
license=('MIT')
makedepends=('git')
depends=('ncurses' 'glibc')
source=("$pkgname::git+https://gitlab.com/eliott.wnr/tclock.git")
sha256sums=('SKIP')

build() {
	cd "$pkgname"
	make
}

package() {
	cd "$pkgname"
	install -Dm755 tclock "$pkgdir/usr/bin/tclock"
	install -Dm644 README.md "$pkgdir/usr/share/doc/$pkgname/README.md"
}

