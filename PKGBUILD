# Maintainer: Eliott Wanner <eliott.wanner@gmail.com>
pkgname='tclock'
pkgver=1
pkgrel=1
pkgdesc="ncurses-based terminal clock written in C"
arch=(any)
url="https://gitlab.com/eliott.wnr/tclock"
license=('MIT')
makedepends=('git')
depends=('ncurses' 'glibc')
source=("git+https://gitlab.com/eliott.wnr/tclock.git#branch=master")
noextract=('tClock_b_s.png' 'tClock_t_b_s.png')
sha256sums=('SKIP')

build() {
	cd "tclock"
	make
}

package() {
  cd "tclock"
  install -Dm755 ./tclock "$pkgdir/usr/bin/tclock"
  install -Dm644 ./README.md "$pkgdir/usr/share/doc/$pkgname"
}
