
./out/p2:     file format elf64-x86-64


Disassembly of section .init:

00000000000008c0 <_init>:
 8c0:	48 83 ec 08          	sub    $0x8,%rsp
 8c4:	48 8b 05 1d 17 20 00 	mov    0x20171d(%rip),%rax        # 201fe8 <__gmon_start__>
 8cb:	48 85 c0             	test   %rax,%rax
 8ce:	74 02                	je     8d2 <_init+0x12>
 8d0:	ff d0                	callq  *%rax
 8d2:	48 83 c4 08          	add    $0x8,%rsp
 8d6:	c3                   	retq   

Disassembly of section .plt:

00000000000008e0 <.plt>:
 8e0:	ff 35 8a 16 20 00    	pushq  0x20168a(%rip)        # 201f70 <_GLOBAL_OFFSET_TABLE_+0x8>
 8e6:	ff 25 8c 16 20 00    	jmpq   *0x20168c(%rip)        # 201f78 <_GLOBAL_OFFSET_TABLE_+0x10>
 8ec:	0f 1f 40 00          	nopl   0x0(%rax)

00000000000008f0 <pthread_join@plt>:
 8f0:	ff 25 8a 16 20 00    	jmpq   *0x20168a(%rip)        # 201f80 <pthread_join@GLIBC_2.2.5>
 8f6:	68 00 00 00 00       	pushq  $0x0
 8fb:	e9 e0 ff ff ff       	jmpq   8e0 <.plt>

0000000000000900 <pthread_create@plt>:
 900:	ff 25 82 16 20 00    	jmpq   *0x201682(%rip)        # 201f88 <pthread_create@GLIBC_2.2.5>
 906:	68 01 00 00 00       	pushq  $0x1
 90b:	e9 d0 ff ff ff       	jmpq   8e0 <.plt>

0000000000000910 <__assert_fail@plt>:
 910:	ff 25 7a 16 20 00    	jmpq   *0x20167a(%rip)        # 201f90 <__assert_fail@GLIBC_2.2.5>
 916:	68 02 00 00 00       	pushq  $0x2
 91b:	e9 c0 ff ff ff       	jmpq   8e0 <.plt>

0000000000000920 <__cxa_atexit@plt>:
 920:	ff 25 72 16 20 00    	jmpq   *0x201672(%rip)        # 201f98 <__cxa_atexit@GLIBC_2.2.5>
 926:	68 03 00 00 00       	pushq  $0x3
 92b:	e9 b0 ff ff ff       	jmpq   8e0 <.plt>

0000000000000930 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>:
 930:	ff 25 6a 16 20 00    	jmpq   *0x20166a(%rip)        # 201fa0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@GLIBCXX_3.4>
 936:	68 04 00 00 00       	pushq  $0x4
 93b:	e9 a0 ff ff ff       	jmpq   8e0 <.plt>

0000000000000940 <_ZNSolsEPFRSoS_E@plt>:
 940:	ff 25 62 16 20 00    	jmpq   *0x201662(%rip)        # 201fa8 <_ZNSolsEPFRSoS_E@GLIBCXX_3.4>
 946:	68 05 00 00 00       	pushq  $0x5
 94b:	e9 90 ff ff ff       	jmpq   8e0 <.plt>

0000000000000950 <__stack_chk_fail@plt>:
 950:	ff 25 5a 16 20 00    	jmpq   *0x20165a(%rip)        # 201fb0 <__stack_chk_fail@GLIBC_2.4>
 956:	68 06 00 00 00       	pushq  $0x6
 95b:	e9 80 ff ff ff       	jmpq   8e0 <.plt>

0000000000000960 <_ZNSt8ios_base4InitC1Ev@plt>:
 960:	ff 25 52 16 20 00    	jmpq   *0x201652(%rip)        # 201fb8 <_ZNSt8ios_base4InitC1Ev@GLIBCXX_3.4>
 966:	68 07 00 00 00       	pushq  $0x7
 96b:	e9 70 ff ff ff       	jmpq   8e0 <.plt>

0000000000000970 <_ZNSolsEi@plt>:
 970:	ff 25 4a 16 20 00    	jmpq   *0x20164a(%rip)        # 201fc0 <_ZNSolsEi@GLIBCXX_3.4>
 976:	68 08 00 00 00       	pushq  $0x8
 97b:	e9 60 ff ff ff       	jmpq   8e0 <.plt>

Disassembly of section .plt.got:

0000000000000980 <__cxa_finalize@plt>:
 980:	ff 25 42 16 20 00    	jmpq   *0x201642(%rip)        # 201fc8 <__cxa_finalize@GLIBC_2.2.5>
 986:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

0000000000000990 <_start>:
 990:	31 ed                	xor    %ebp,%ebp
 992:	49 89 d1             	mov    %rdx,%r9
 995:	5e                   	pop    %rsi
 996:	48 89 e2             	mov    %rsp,%rdx
 999:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
 99d:	50                   	push   %rax
 99e:	54                   	push   %rsp
 99f:	4c 8d 05 3a 04 00 00 	lea    0x43a(%rip),%r8        # de0 <__libc_csu_fini>
 9a6:	48 8d 0d c3 03 00 00 	lea    0x3c3(%rip),%rcx        # d70 <__libc_csu_init>
 9ad:	48 8d 3d 92 01 00 00 	lea    0x192(%rip),%rdi        # b46 <main>
 9b4:	ff 15 26 16 20 00    	callq  *0x201626(%rip)        # 201fe0 <__libc_start_main@GLIBC_2.2.5>
 9ba:	f4                   	hlt    
 9bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000009c0 <deregister_tm_clones>:
 9c0:	48 8d 3d 49 16 20 00 	lea    0x201649(%rip),%rdi        # 202010 <__TMC_END__>
 9c7:	55                   	push   %rbp
 9c8:	48 8d 05 41 16 20 00 	lea    0x201641(%rip),%rax        # 202010 <__TMC_END__>
 9cf:	48 39 f8             	cmp    %rdi,%rax
 9d2:	48 89 e5             	mov    %rsp,%rbp
 9d5:	74 19                	je     9f0 <deregister_tm_clones+0x30>
 9d7:	48 8b 05 fa 15 20 00 	mov    0x2015fa(%rip),%rax        # 201fd8 <_ITM_deregisterTMCloneTable>
 9de:	48 85 c0             	test   %rax,%rax
 9e1:	74 0d                	je     9f0 <deregister_tm_clones+0x30>
 9e3:	5d                   	pop    %rbp
 9e4:	ff e0                	jmpq   *%rax
 9e6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 9ed:	00 00 00 
 9f0:	5d                   	pop    %rbp
 9f1:	c3                   	retq   
 9f2:	0f 1f 40 00          	nopl   0x0(%rax)
 9f6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 9fd:	00 00 00 

0000000000000a00 <register_tm_clones>:
 a00:	48 8d 3d 09 16 20 00 	lea    0x201609(%rip),%rdi        # 202010 <__TMC_END__>
 a07:	48 8d 35 02 16 20 00 	lea    0x201602(%rip),%rsi        # 202010 <__TMC_END__>
 a0e:	55                   	push   %rbp
 a0f:	48 29 fe             	sub    %rdi,%rsi
 a12:	48 89 e5             	mov    %rsp,%rbp
 a15:	48 c1 fe 03          	sar    $0x3,%rsi
 a19:	48 89 f0             	mov    %rsi,%rax
 a1c:	48 c1 e8 3f          	shr    $0x3f,%rax
 a20:	48 01 c6             	add    %rax,%rsi
 a23:	48 d1 fe             	sar    %rsi
 a26:	74 18                	je     a40 <register_tm_clones+0x40>
 a28:	48 8b 05 c1 15 20 00 	mov    0x2015c1(%rip),%rax        # 201ff0 <_ITM_registerTMCloneTable>
 a2f:	48 85 c0             	test   %rax,%rax
 a32:	74 0c                	je     a40 <register_tm_clones+0x40>
 a34:	5d                   	pop    %rbp
 a35:	ff e0                	jmpq   *%rax
 a37:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
 a3e:	00 00 
 a40:	5d                   	pop    %rbp
 a41:	c3                   	retq   
 a42:	0f 1f 40 00          	nopl   0x0(%rax)
 a46:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 a4d:	00 00 00 

0000000000000a50 <__do_global_dtors_aux>:
 a50:	80 3d d9 16 20 00 00 	cmpb   $0x0,0x2016d9(%rip)        # 202130 <completed.7698>
 a57:	75 2f                	jne    a88 <__do_global_dtors_aux+0x38>
 a59:	48 83 3d 67 15 20 00 	cmpq   $0x0,0x201567(%rip)        # 201fc8 <__cxa_finalize@GLIBC_2.2.5>
 a60:	00 
 a61:	55                   	push   %rbp
 a62:	48 89 e5             	mov    %rsp,%rbp
 a65:	74 0c                	je     a73 <__do_global_dtors_aux+0x23>
 a67:	48 8b 3d 9a 15 20 00 	mov    0x20159a(%rip),%rdi        # 202008 <__dso_handle>
 a6e:	e8 0d ff ff ff       	callq  980 <__cxa_finalize@plt>
 a73:	e8 48 ff ff ff       	callq  9c0 <deregister_tm_clones>
 a78:	c6 05 b1 16 20 00 01 	movb   $0x1,0x2016b1(%rip)        # 202130 <completed.7698>
 a7f:	5d                   	pop    %rbp
 a80:	c3                   	retq   
 a81:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
 a88:	f3 c3                	repz retq 
 a8a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000000a90 <frame_dummy>:
 a90:	55                   	push   %rbp
 a91:	48 89 e5             	mov    %rsp,%rbp
 a94:	5d                   	pop    %rbp
 a95:	e9 66 ff ff ff       	jmpq   a00 <register_tm_clones>

0000000000000a9a <_ZL8mythreadPv>:
 a9a:	55                   	push   %rbp
 a9b:	48 89 e5             	mov    %rsp,%rbp
 a9e:	48 83 ec 20          	sub    $0x20,%rsp
 aa2:	48 89 7d e8          	mov    %rdi,-0x18(%rbp)
 aa6:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 aaa:	48 89 c6             	mov    %rax,%rsi
 aad:	48 8d 3d 6c 15 20 00 	lea    0x20156c(%rip),%rdi        # 202020 <_ZSt4cout@@GLIBCXX_3.4>
 ab4:	e8 77 fe ff ff       	callq  930 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
 ab9:	48 8d 35 39 03 00 00 	lea    0x339(%rip),%rsi        # df9 <_ZStL19piecewise_construct+0x1>
 ac0:	48 89 c7             	mov    %rax,%rdi
 ac3:	e8 68 fe ff ff       	callq  930 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
 ac8:	48 89 c2             	mov    %rax,%rdx
 acb:	48 8b 05 fe 14 20 00 	mov    0x2014fe(%rip),%rax        # 201fd0 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
 ad2:	48 89 c6             	mov    %rax,%rsi
 ad5:	48 89 d7             	mov    %rdx,%rdi
 ad8:	e8 63 fe ff ff       	callq  940 <_ZNSolsEPFRSoS_E@plt>
 add:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%rbp)
 ae4:	f2 0f 2a 45 fc       	cvtsi2sdl -0x4(%rbp),%xmm0
 ae9:	f2 0f 10 0d 57 03 00 	movsd  0x357(%rip),%xmm1        # e48 <_ZZ4mainE19__PRETTY_FUNCTION__+0x10>
 af0:	00 
 af1:	66 0f 2e c8          	ucomisd %xmm0,%xmm1
 af5:	76 15                	jbe    b0c <_ZL8mythreadPv+0x72>
 af7:	8b 05 3b 16 20 00    	mov    0x20163b(%rip),%eax        # 202138 <_ZL5count>
 afd:	83 c0 01             	add    $0x1,%eax
 b00:	89 05 32 16 20 00    	mov    %eax,0x201632(%rip)        # 202138 <_ZL5count>
 b06:	83 45 fc 01          	addl   $0x1,-0x4(%rbp)
 b0a:	eb d8                	jmp    ae4 <_ZL8mythreadPv+0x4a>
 b0c:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 b10:	48 89 c6             	mov    %rax,%rsi
 b13:	48 8d 3d 06 15 20 00 	lea    0x201506(%rip),%rdi        # 202020 <_ZSt4cout@@GLIBCXX_3.4>
 b1a:	e8 11 fe ff ff       	callq  930 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
 b1f:	48 8d 35 da 02 00 00 	lea    0x2da(%rip),%rsi        # e00 <_ZStL19piecewise_construct+0x8>
 b26:	48 89 c7             	mov    %rax,%rdi
 b29:	e8 02 fe ff ff       	callq  930 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
 b2e:	48 89 c2             	mov    %rax,%rdx
 b31:	48 8b 05 98 14 20 00 	mov    0x201498(%rip),%rax        # 201fd0 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
 b38:	48 89 c6             	mov    %rax,%rsi
 b3b:	48 89 d7             	mov    %rdx,%rdi
 b3e:	e8 fd fd ff ff       	callq  940 <_ZNSolsEPFRSoS_E@plt>
 b43:	90                   	nop
 b44:	c9                   	leaveq 
 b45:	c3                   	retq   

0000000000000b46 <main>:
 b46:	55                   	push   %rbp
 b47:	48 89 e5             	mov    %rsp,%rbp
 b4a:	48 83 ec 20          	sub    $0x20,%rsp
 b4e:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
 b55:	00 00 
 b57:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
 b5b:	31 c0                	xor    %eax,%eax
 b5d:	48 8d 35 a1 02 00 00 	lea    0x2a1(%rip),%rsi        # e05 <_ZStL19piecewise_construct+0xd>
 b64:	48 8d 3d b5 14 20 00 	lea    0x2014b5(%rip),%rdi        # 202020 <_ZSt4cout@@GLIBCXX_3.4>
 b6b:	e8 c0 fd ff ff       	callq  930 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
 b70:	48 89 c2             	mov    %rax,%rdx
 b73:	48 8b 05 56 14 20 00 	mov    0x201456(%rip),%rax        # 201fd0 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
 b7a:	48 89 c6             	mov    %rax,%rsi
 b7d:	48 89 d7             	mov    %rdx,%rdi
 b80:	e8 bb fd ff ff       	callq  940 <_ZNSolsEPFRSoS_E@plt>
 b85:	48 8d 45 e8          	lea    -0x18(%rbp),%rax
 b89:	48 8d 0d 80 02 00 00 	lea    0x280(%rip),%rcx        # e10 <_ZStL19piecewise_construct+0x18>
 b90:	48 8d 15 03 ff ff ff 	lea    -0xfd(%rip),%rdx        # a9a <_ZL8mythreadPv>
 b97:	be 00 00 00 00       	mov    $0x0,%esi
 b9c:	48 89 c7             	mov    %rax,%rdi
 b9f:	e8 5c fd ff ff       	callq  900 <pthread_create@plt>
 ba4:	89 45 e4             	mov    %eax,-0x1c(%rbp)
 ba7:	83 7d e4 00          	cmpl   $0x0,-0x1c(%rbp)
 bab:	74 1f                	je     bcc <main+0x86>
 bad:	48 8d 0d 84 02 00 00 	lea    0x284(%rip),%rcx        # e38 <_ZZ4mainE19__PRETTY_FUNCTION__>
 bb4:	ba 22 00 00 00       	mov    $0x22,%edx
 bb9:	48 8d 35 52 02 00 00 	lea    0x252(%rip),%rsi        # e12 <_ZStL19piecewise_construct+0x1a>
 bc0:	48 8d 3d 51 02 00 00 	lea    0x251(%rip),%rdi        # e18 <_ZStL19piecewise_construct+0x20>
 bc7:	e8 44 fd ff ff       	callq  910 <__assert_fail@plt>
 bcc:	48 8d 45 f0          	lea    -0x10(%rbp),%rax
 bd0:	48 8d 0d 49 02 00 00 	lea    0x249(%rip),%rcx        # e20 <_ZStL19piecewise_construct+0x28>
 bd7:	48 8d 15 bc fe ff ff 	lea    -0x144(%rip),%rdx        # a9a <_ZL8mythreadPv>
 bde:	be 00 00 00 00       	mov    $0x0,%esi
 be3:	48 89 c7             	mov    %rax,%rdi
 be6:	e8 15 fd ff ff       	callq  900 <pthread_create@plt>
 beb:	89 45 e4             	mov    %eax,-0x1c(%rbp)
 bee:	83 7d e4 00          	cmpl   $0x0,-0x1c(%rbp)
 bf2:	74 1f                	je     c13 <main+0xcd>
 bf4:	48 8d 0d 3d 02 00 00 	lea    0x23d(%rip),%rcx        # e38 <_ZZ4mainE19__PRETTY_FUNCTION__>
 bfb:	ba 24 00 00 00       	mov    $0x24,%edx
 c00:	48 8d 35 0b 02 00 00 	lea    0x20b(%rip),%rsi        # e12 <_ZStL19piecewise_construct+0x1a>
 c07:	48 8d 3d 0a 02 00 00 	lea    0x20a(%rip),%rdi        # e18 <_ZStL19piecewise_construct+0x20>
 c0e:	e8 fd fc ff ff       	callq  910 <__assert_fail@plt>
 c13:	48 8b 45 e8          	mov    -0x18(%rbp),%rax
 c17:	be 00 00 00 00       	mov    $0x0,%esi
 c1c:	48 89 c7             	mov    %rax,%rdi
 c1f:	e8 cc fc ff ff       	callq  8f0 <pthread_join@plt>
 c24:	89 45 e4             	mov    %eax,-0x1c(%rbp)
 c27:	83 7d e4 00          	cmpl   $0x0,-0x1c(%rbp)
 c2b:	74 1f                	je     c4c <main+0x106>
 c2d:	48 8d 0d 04 02 00 00 	lea    0x204(%rip),%rcx        # e38 <_ZZ4mainE19__PRETTY_FUNCTION__>
 c34:	ba 27 00 00 00       	mov    $0x27,%edx
 c39:	48 8d 35 d2 01 00 00 	lea    0x1d2(%rip),%rsi        # e12 <_ZStL19piecewise_construct+0x1a>
 c40:	48 8d 3d d1 01 00 00 	lea    0x1d1(%rip),%rdi        # e18 <_ZStL19piecewise_construct+0x20>
 c47:	e8 c4 fc ff ff       	callq  910 <__assert_fail@plt>
 c4c:	48 8b 45 f0          	mov    -0x10(%rbp),%rax
 c50:	be 00 00 00 00       	mov    $0x0,%esi
 c55:	48 89 c7             	mov    %rax,%rdi
 c58:	e8 93 fc ff ff       	callq  8f0 <pthread_join@plt>
 c5d:	89 45 e4             	mov    %eax,-0x1c(%rbp)
 c60:	83 7d e4 00          	cmpl   $0x0,-0x1c(%rbp)
 c64:	74 1f                	je     c85 <main+0x13f>
 c66:	48 8d 0d cb 01 00 00 	lea    0x1cb(%rip),%rcx        # e38 <_ZZ4mainE19__PRETTY_FUNCTION__>
 c6d:	ba 29 00 00 00       	mov    $0x29,%edx
 c72:	48 8d 35 99 01 00 00 	lea    0x199(%rip),%rsi        # e12 <_ZStL19piecewise_construct+0x1a>
 c79:	48 8d 3d 98 01 00 00 	lea    0x198(%rip),%rdi        # e18 <_ZStL19piecewise_construct+0x20>
 c80:	e8 8b fc ff ff       	callq  910 <__assert_fail@plt>
 c85:	48 8d 35 96 01 00 00 	lea    0x196(%rip),%rsi        # e22 <_ZStL19piecewise_construct+0x2a>
 c8c:	48 8d 3d 8d 13 20 00 	lea    0x20138d(%rip),%rdi        # 202020 <_ZSt4cout@@GLIBCXX_3.4>
 c93:	e8 98 fc ff ff       	callq  930 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
 c98:	48 89 c2             	mov    %rax,%rdx
 c9b:	8b 05 97 14 20 00    	mov    0x201497(%rip),%eax        # 202138 <_ZL5count>
 ca1:	89 c6                	mov    %eax,%esi
 ca3:	48 89 d7             	mov    %rdx,%rdi
 ca6:	e8 c5 fc ff ff       	callq  970 <_ZNSolsEi@plt>
 cab:	48 89 c2             	mov    %rax,%rdx
 cae:	48 8b 05 1b 13 20 00 	mov    0x20131b(%rip),%rax        # 201fd0 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
 cb5:	48 89 c6             	mov    %rax,%rsi
 cb8:	48 89 d7             	mov    %rdx,%rdi
 cbb:	e8 80 fc ff ff       	callq  940 <_ZNSolsEPFRSoS_E@plt>
 cc0:	48 8d 35 68 01 00 00 	lea    0x168(%rip),%rsi        # e2f <_ZStL19piecewise_construct+0x37>
 cc7:	48 8d 3d 52 13 20 00 	lea    0x201352(%rip),%rdi        # 202020 <_ZSt4cout@@GLIBCXX_3.4>
 cce:	e8 5d fc ff ff       	callq  930 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
 cd3:	48 89 c2             	mov    %rax,%rdx
 cd6:	48 8b 05 f3 12 20 00 	mov    0x2012f3(%rip),%rax        # 201fd0 <_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GLIBCXX_3.4>
 cdd:	48 89 c6             	mov    %rax,%rsi
 ce0:	48 89 d7             	mov    %rdx,%rdi
 ce3:	e8 58 fc ff ff       	callq  940 <_ZNSolsEPFRSoS_E@plt>
 ce8:	b8 00 00 00 00       	mov    $0x0,%eax
 ced:	48 8b 4d f8          	mov    -0x8(%rbp),%rcx
 cf1:	64 48 33 0c 25 28 00 	xor    %fs:0x28,%rcx
 cf8:	00 00 
 cfa:	74 05                	je     d01 <main+0x1bb>
 cfc:	e8 4f fc ff ff       	callq  950 <__stack_chk_fail@plt>
 d01:	c9                   	leaveq 
 d02:	c3                   	retq   

0000000000000d03 <_Z41__static_initialization_and_destruction_0ii>:
 d03:	55                   	push   %rbp
 d04:	48 89 e5             	mov    %rsp,%rbp
 d07:	48 83 ec 10          	sub    $0x10,%rsp
 d0b:	89 7d fc             	mov    %edi,-0x4(%rbp)
 d0e:	89 75 f8             	mov    %esi,-0x8(%rbp)
 d11:	83 7d fc 01          	cmpl   $0x1,-0x4(%rbp)
 d15:	75 32                	jne    d49 <_Z41__static_initialization_and_destruction_0ii+0x46>
 d17:	81 7d f8 ff ff 00 00 	cmpl   $0xffff,-0x8(%rbp)
 d1e:	75 29                	jne    d49 <_Z41__static_initialization_and_destruction_0ii+0x46>
 d20:	48 8d 3d 0d 14 20 00 	lea    0x20140d(%rip),%rdi        # 202134 <_ZStL8__ioinit>
 d27:	e8 34 fc ff ff       	callq  960 <_ZNSt8ios_base4InitC1Ev@plt>
 d2c:	48 8d 15 d5 12 20 00 	lea    0x2012d5(%rip),%rdx        # 202008 <__dso_handle>
 d33:	48 8d 35 fa 13 20 00 	lea    0x2013fa(%rip),%rsi        # 202134 <_ZStL8__ioinit>
 d3a:	48 8b 05 b7 12 20 00 	mov    0x2012b7(%rip),%rax        # 201ff8 <_ZNSt8ios_base4InitD1Ev@GLIBCXX_3.4>
 d41:	48 89 c7             	mov    %rax,%rdi
 d44:	e8 d7 fb ff ff       	callq  920 <__cxa_atexit@plt>
 d49:	90                   	nop
 d4a:	c9                   	leaveq 
 d4b:	c3                   	retq   

0000000000000d4c <_GLOBAL__sub_I_main>:
 d4c:	55                   	push   %rbp
 d4d:	48 89 e5             	mov    %rsp,%rbp
 d50:	be ff ff 00 00       	mov    $0xffff,%esi
 d55:	bf 01 00 00 00       	mov    $0x1,%edi
 d5a:	e8 a4 ff ff ff       	callq  d03 <_Z41__static_initialization_and_destruction_0ii>
 d5f:	5d                   	pop    %rbp
 d60:	c3                   	retq   
 d61:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 d68:	00 00 00 
 d6b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

0000000000000d70 <__libc_csu_init>:
 d70:	41 57                	push   %r15
 d72:	41 56                	push   %r14
 d74:	49 89 d7             	mov    %rdx,%r15
 d77:	41 55                	push   %r13
 d79:	41 54                	push   %r12
 d7b:	4c 8d 25 be 0f 20 00 	lea    0x200fbe(%rip),%r12        # 201d40 <__frame_dummy_init_array_entry>
 d82:	55                   	push   %rbp
 d83:	48 8d 2d c6 0f 20 00 	lea    0x200fc6(%rip),%rbp        # 201d50 <__init_array_end>
 d8a:	53                   	push   %rbx
 d8b:	41 89 fd             	mov    %edi,%r13d
 d8e:	49 89 f6             	mov    %rsi,%r14
 d91:	4c 29 e5             	sub    %r12,%rbp
 d94:	48 83 ec 08          	sub    $0x8,%rsp
 d98:	48 c1 fd 03          	sar    $0x3,%rbp
 d9c:	e8 1f fb ff ff       	callq  8c0 <_init>
 da1:	48 85 ed             	test   %rbp,%rbp
 da4:	74 20                	je     dc6 <__libc_csu_init+0x56>
 da6:	31 db                	xor    %ebx,%ebx
 da8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
 daf:	00 
 db0:	4c 89 fa             	mov    %r15,%rdx
 db3:	4c 89 f6             	mov    %r14,%rsi
 db6:	44 89 ef             	mov    %r13d,%edi
 db9:	41 ff 14 dc          	callq  *(%r12,%rbx,8)
 dbd:	48 83 c3 01          	add    $0x1,%rbx
 dc1:	48 39 dd             	cmp    %rbx,%rbp
 dc4:	75 ea                	jne    db0 <__libc_csu_init+0x40>
 dc6:	48 83 c4 08          	add    $0x8,%rsp
 dca:	5b                   	pop    %rbx
 dcb:	5d                   	pop    %rbp
 dcc:	41 5c                	pop    %r12
 dce:	41 5d                	pop    %r13
 dd0:	41 5e                	pop    %r14
 dd2:	41 5f                	pop    %r15
 dd4:	c3                   	retq   
 dd5:	90                   	nop
 dd6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 ddd:	00 00 00 

0000000000000de0 <__libc_csu_fini>:
 de0:	f3 c3                	repz retq 

Disassembly of section .fini:

0000000000000de4 <_fini>:
 de4:	48 83 ec 08          	sub    $0x8,%rsp
 de8:	48 83 c4 08          	add    $0x8,%rsp
 dec:	c3                   	retq   
