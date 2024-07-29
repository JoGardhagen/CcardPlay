# CCardPlay

<p>This is a simple Card game Vänd-8 Written in c 
<p>
<p>
Start
    Initialize Deck
    Shuffle Deck
    Initialize Hand
    Initialize Discard Pile

    // Draw initial cards to the hand
    For i from 1 to INITIAL_HAND_SIZE
        Draw Card from Deck
        Add Card to Hand

    // Draw a starting card to the discard pile
    Draw Card from Deck
    Set Top Card to Drawn Card
    Add Top Card to Discard Pile

    While Hand is not empty
        Display Hand
        Display Top Card

        Prompt User to Choose a Card (1 to N, or 0 to Draw 3 Cards)
        Read User Choice

        If Choice is 0
            Draw 3 Cards from Deck
            Add Cards to Hand
            Continue to next iteration

        If Choice is invalid
            Display error message
            Continue to next iteration

        // Select the chosen card from the hand
        Select Card from Hand based on User Choice

        If Selected Card is Playable with Top Card
            // Check if there are multiple cards of the same rank in hand
            If Player has multiple cards of the same rank
                Prompt User to decide if they want to play all cards of the same rank
                If User agrees
                    For each card of the same rank in hand
                        Prompt User to confirm playing the card
                        If User confirms
                            Play the card
                            Add Card to Discard Pile
                            Remove Card from Hand

            // Play the selected card
            Update Top Card to Selected Card
            Add Selected Card to Discard Pile
            Remove Selected Card from Hand

            // If the card played is an 8, prompt to choose a new suit
            If Selected Card is an 8
                Prompt User to Choose a New Suit
                Update Top Card Suit to Chosen Suit

        Else
            Display message indicating that the card is not playable

    Display message indicating that all cards have been played
End

<p>