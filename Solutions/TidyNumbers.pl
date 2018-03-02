main(File):-open(File, read, Stream),
            open("out.txt", write, Stream2),
            read_line(Stream, [K]),
            read_and_write(Stream ,Stream2, K,1),
            close(Stream),
            close(Stream2),!.

read_and_write(Stream, Stream2, K,Case):- ( K =:= 0 -> ! ; K>0,read_line(Stream, [N]),
                                            find_number(N,M), 
                                            write(Stream2,"Case #"),write(Stream2,Case),
                                            write(Stream2,": "),write(Stream2,M),write(Stream2,"\n"),
                                            K1 is K-1, Case1 is Case+1,
                                            read_and_write(Stream, Stream2, K1, Case1)).    

read_line(Stream, List) :- read_line_to_codes(Stream, Line),
                           atom_codes(A, Line),
                           atomic_list_concat(As, ' ', A),
                           maplist(atom_number, As, List).

find_number(N,M):- number_codes(N,L), (valid(L) -> M = N,! ; find_pos(L,0,K),length(L,K1),K2 is K1-K-1,
                   length(L1,K2), append(_,L1,L), 
                   number_codes(N0,L1), M is N-N0-1,!) .


find_pos([H,H1|T],N,M):- (H1=<H -> M = N ; N1 is N+1, find_pos([H1|T],N1,M)).

valid([_]).
valid([X,Y|T]):- X =<Y , valid([Y|T]).