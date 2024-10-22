# Maintainer: Eliott Wanner <eliott.wanner@gmail.com>
pkgname='tclock'
pkgver=1
pkgrel=1
pkgdesc="ncurses-based terminal clock written in C"
arch=(any)
url="https://gitlab.com/eliott.wnr/tClock"
license=('MIT')
makedepends=('git')
depends=('ncurses' 'glibc')
source=("git+https://gitlab.com/eliott.wnr/tClock.git#branch=make")
noextract=('tClock_b_s.png' 'tClock_t_b_s.png')
sha256sums=('SKIP')

build() {
	cd "tClock"
	make
}

package() {
  cd "tClock"
  install -Dm755 ./tClock "$pkgdir/usr/bin/tClock"
  install -Dm644 ./README.md "$pkgdir/usr/share/doc/$pkgname"
}
