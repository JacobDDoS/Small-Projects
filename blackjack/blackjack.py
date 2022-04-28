import random as rn
usersMoney = 100
cardsUsed = []

def whatUserWantsToDo():
  print("0: Play a game of Blackjack")
  print("1: Enter some more money")
  print("2: Check current balance")
  print("3: Clear screen")
  usersChoice = input("Please enter your choice: ")
  while usersChoice not in ["0", "1", "2", "3"]:
    print("Invalid choice.")
    usersChoice = input("Please enter your choice: ")
  return usersChoice

def drawCard():
  global cardsUsed
  cardDrawn = rn.randint(0, 51)
  while cardDrawn in cardsUsed:
    cardDrawn = rn.randint(0, 51)
  cardsUsed.append(cardDrawn)
  return cardDrawn

def cardValue(card):
  if card.isdigit():
    return int(card)
  elif card == "Ace":
    return 11
  else:
    return 10

def game(bet):
  global usersMoney, cardsUsed
  suits = ["Diamonds", "Clubs", "Spades", "Hearts"]
  types = ["2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"]
  allCards = []
  cardsUsed = []
  playersCard = []
  dealersCard = []
  for suit in suits:
    for type in types:
      allCards.append([type, suit])

  for _ in range(2):
    card = drawCard()
    playersCard.append(card)

  for _ in range(2):
    card = drawCard()
    dealersCard.append(card)

  firstPlayerCardValue = cardValue(allCards[playersCard[0]][0])
  secondPlayerCardValue = cardValue(allCards[playersCard[1]][0])

  print('\033c')

  print("Your cards (" + str(firstPlayerCardValue + secondPlayerCardValue) + "):")
  print(allCards[playersCard[0]][0] + " of " + allCards[playersCard[0]][1])
  print(allCards[playersCard[1]][0] + " of " + allCards[playersCard[1]][1])

  print()
  print("Dealer shows: ") 
  print(allCards[dealersCard[0]][0] + " of " + allCards[dealersCard[0]][1])

  if firstPlayerCardValue + secondPlayerCardValue == 21:
    print()
    print("BLACKJACK!!!")
    print("You win $" + str(bet*1.5) + "!")
    usersMoney += bet*1.5
    return

  playersTotal = firstPlayerCardValue + secondPlayerCardValue
  while True:
    print()
    if playersTotal > 21:
      print("BUSTED!")
      print()
      usersMoney -= bet
      return 

    usersInput = input("Would you like to draw another card? (y/n): ")
    while usersInput not in ["y", "n"]:
      usersInput = input("Would you like to draw another card? (y/n): ")
    if usersInput == "y":
      newCard = drawCard()
      print("You drew " + allCards[newCard][0] + " of " + allCards[newCard][1])
      playersTotal += cardValue(allCards[newCard][0])
      print("New total: " + str(playersTotal))
    else: 
      print("The dealer reveals their other card to be the " + allCards[dealersCard[1]][0] + " of " + allCards[dealersCard[1]][1])
      dealersFirstCardValue = cardValue(allCards[dealersCard[0]][0])
      dealersSecondCardValue = cardValue(allCards[dealersCard[1]][0])
      dealersTotal = dealersFirstCardValue + dealersSecondCardValue

      while dealersTotal < 16:
        newCard = drawCard()
        print("The dealer drew the " + allCards[newCard][0] + " of " + allCards[newCard][1])
        dealersTotal += cardValue(allCards[newCard][0])
        print("The dealers new total is " + str(dealersTotal))

      if dealersTotal > 21:
        print("The dealer busts!!!")
        print("You win $" + str(bet) + "!!!")
        usersMoney += bet


      if dealersTotal > playersTotal:
        print("You lost!")
        usersMoney -= bet
      elif playersTotal > dealersTotal:
        print("You won!!")
        print("You won $" + str(bet))
        usersMoney += bet
      else:
        print("Draw!")

      return
          
def addMoney(amount):
  global usersMoney
  usersMoney += amount


while True:
  usersChoice = whatUserWantsToDo()
  if usersChoice == "0":
    amountToBet = round(float(input("How much would you like to bet? : ")), 2)
    while amountToBet > usersMoney or amountToBet <= 0:
      print("Invalid. Please choose a value greater than $0 and less than the current amount of money you have.")
      amountToBet = round(float(input("How much would you like to bet? : ")), 2)

    game(amountToBet)
  elif usersChoice == "1":
    amountToAdd = round(float(input("How much would you like to insert? : ")), 2)
    while amountToAdd <= 0:
      print("Please insert a number greater than 0.")
      amountToAdd = round(float(input("How much would you like to insert? : ")), 2)

    addMoney(amountToAdd)

  elif usersChoice == "2":
    print("Current balance: $", end="")
    print("{:0.2f}".format(usersMoney))

  elif usersChoice == "3":
    print("\033c")
    
  print()