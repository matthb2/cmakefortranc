      program test
      real*8, allocatable :: threedarray(:,:,:)
      real*4 x
      integer boundx
      integer boundy
      integer boundz
      integer l
      boundx = 10
      boundy = 11
      boundz = 12
      l=1
      x = 5
      x = calculate_x(x)
      allocate(threedarray(boundx,boundy,boundz))
      write (*,*) 'x is ', x
!      write (*,*) 'Fortran!'
      do i = 1, boundx
          do j = 1, boundy
              do k = 1, boundz
                  threedarray(i,j,k) = l
!                  write(*,*) l
                  l=l+1
              enddo
          enddo
      enddo
      call access_array(threedarray,boundx,boundy,boundz,l)
      stop
      end
