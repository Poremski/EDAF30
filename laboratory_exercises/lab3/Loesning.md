# Lösning

Bug (what function?, what line?) | Describe the problem. | How did you find hte bug?
---|---|---
`UserTable::addUser(User u)` | Variabeln `n` i `UserTable::addUser` är konstant med värdet `0` vilket medför att inga ny användare kan läggas till. | Noterade att inga användare skrevs ut av `print()` trots att konstruktorn tar in datafilen. Genom `std::cout` gjordes observation att `pos` inte ändrades.
`UserTable::find(int c)` | Returnerar `user_not_found` trots att användaren existerar i datafilen. | Genom kompilatorn: `63:20: if (midnbr = c)` som ska vara `==`. Efter korrigering hittas `21330` men ej `21331`. Efter en `std::cout` noterades att `mid` samt `midnbr` vilket löstes med `low <= high`.
`UserTable::find(string name)` | Returnerar `user_not_found`. | Efter en okulär besiktning stod det klart att på rad 78 kommer else-förfrågningen innehållandes `user_not_found` att köras när första kontrollen av elementen inte är korrekt. Genom dess borttagande löstes problemet.
`UserTable::testFindNumber()` | Funktionen existerar inte. | Noterat att det finns `testFindNbr()`. Ändrade till `testFindNbr(const UserTable& ut)` och skapade en ny funktion `testFindNumber()` som returnerar `testFindNbr(*this)`.
