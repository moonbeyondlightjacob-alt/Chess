char piece_to_char(piece Piece){

    char The_piece;

    if(Piece.color==White){
        switch(Piece.type){
            case King:
                The_piece='k';
                 break;
            case Queen:
                The_piece='q';
                 break;
            case Rock:
                The_piece='r';
                 break;
            case Bishop:
                The_piece='b';
                 break;
            case Knight:
                The_piece='n';
                 break;
            case Pawn:
                The_piece='p';
                break;
            default:
                return ' ';
        }
    }
    if(Piece.color==Black){
         switch(piece.type){
            case King:
                The_piece='K';
                 break;
            case Queen:
                The_piece='Q';
                 break;
            case Rock:
                The_piece='R';
                 break;
            case Bishop:
                The_piece='B';
                 break;
            case Knight:
                The_piece='N';
                 break;
            case Pawn:
                The_piece='P';
                break;
            default:
                return ' ';
        }

    }
    return The_piece;
}