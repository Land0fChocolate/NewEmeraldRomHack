# Pokémon Energized Emerald

A reimagining of Pokemon Emerald with the aim to expand and enhance the game. 

This is a rom hack of Pokemon Emerald using pokeemerald-expansion as its base: https://github.com/rh-hideout/pokeemerald-expansion.
The project started in December 2021, using the version of pokeemerald-expansion at the time. Most updates to pokeemerald-expansion have been implemented in Energized Emerald. 

# Changelog

- Many post gen 3 features from pokeemerald-expansion are in this ROM.
	- Including physical/special split, fairy types, new moves, new items, new Pokemon species, regional species variants.
- All Pokemon from gens 1, 2 and 3 are accessible. 
	- Those Pokemon with post gen 3 evolutions and pre-evolutions have those available as well.
	- Many regional variants of gen 1, 2 and 3 Pokemon are available.
- Pokemon can have up to 3 active abilities at once, dependant on their species.
	- Many Pokemon have had their ability sets updated to better fit their theme and gameplay. (TODO: make a list of ability stat changes somewhere).
	- Some vanilla abilities have been updated to make them more useful and compatible with the new multi ability change (listed below).
	- Moves that work around abilities have been updated as well.
- New moves and abilities (listed below).
- Many gameplay adjustments to vanilla moves (Listed below). 
	- Changes to level up, Egg learnsets, TM learnsets and Tutor learnsets of Pokemon (TODO: make list).
	- Pokemon will attempt to learn a new move upon evolution.
	- Hoenn move tutors can now teach their moves endlessly.
- New tutor moves added.
- Some Pokemon have base stat changes to better fit their theme and gameplay. Treecko, Spheal lines have Attack and Special Attack swapped for example. (TODO: make list)
- HMs have been removed and Pokemon can use the HM field commands without needing to learn the move. Only the relevant badge and a compatible Pokemon species are required to traverse obstacles.
- Pokemon IVs and EVs can be viewed in the summary screen by pressing the L and R buttons.
- Wild Encounters adjusted.
	- Both Latias and Latios are available roaming at the same time.
	- All Legendary and Mythical Pokemon can be repeatedly acquired.
	- There is a small chance for a wild encounter to be a double battle.
	- There is a small chance to encounter a wild Pokemon a much higher level than others in the same area.
- Repeatedly acquirable fossils.
- Level up requirements of many Pokemon have been tweaked. Starters evolve a little later. Pokemon with unnecessarily late evolutions (like the fossils, Rufflet, Deino) evolve earlier (TODO: list them below).
- Tradeback guy added. Provides a service for the player to trade Pokemon with themselves and trigger trade evolutions.
- Ice types have their special defense boosted by 50% in hail.
- Steven is back to being champion and Wallace back to being a gym leader.
- Prof Birch is chased by a Poochyena instead of a Zigzagoon, just like in Ruby/Sapphire.
- Opponent Trainer parties have been updated.
- New opponent Trainer classes.
- Contests have been updated to take on the various changes.
	- More Pokemon added to opponent lists, especially new Pokemon.
	- Opponents have updated movesets.
	- Contest moves have been updated to be more like gen 6.
	- More move combos.
- Battle Frontier changes
	- Opponent Pokemon list updated with new Pokemon, new items and new moves.
	- Battle Palace is now inverse battle themed.
	- Battle Dome has its move scores updated.
	- Battle Factory has its opponent tips updated.
- Map layout changes, including new areas to explore that have new Pokemon (post game).
- New overworld sprites and graphics.
- Graphical updates to many existing overworld sprites and environments.
- Various story changes. Includes aspects from ORAS, though has an entirely new story.
- Gym Leaders do more:
	- Roxanne trades evolution stones for fossils.
	- Brawly can give a random shard daily.
	- Flannery can EV train one of your Pokemon daily.
	- Winona gives a random rare berry daily.
	- Tate and Liza grant access to Jirachi.
- Item changes
	- Quick Claw now increases speed by 10% when user is below 50% health.
	- Vitamins give 20 EVs instead of 10.
	- Prices of various items adjusted.
	- Nature Mints added
	- TMs have infinite use.
	- TMs from #51 to #99 have been added. They are similar to the gen 7 TM set (TODO: make list).
	- Existing shops sell more stuff, including post gen 3 items.
	- New shops that sell more stuff, including post gen 3 items.
	- More daily berry giveaways and of newer gen berries too. All berries up to Starf are accessible.
	- The Berry Master's wife phrases for rare berries are now hinted at by NPCs in game. You can also now repeatedly get those rare berries from her. 
	- All item use, except for Poke Balls, is disabled from battles by default. NPCs don't use items either. Players may re-enable items in the options menu if they wish.
- Deoxys is able to change forms by interacting with meteorites in the overworld.
- Groomer, EV trainer and IV trainer NPCs have been added.
- Better berry trees
	- Yield rates have increased.
	- Interaction with berry trees and soil patches is quicker.
	- Rain waters berry trees.
- Number of Feebas spots is tripled.
- Removed badge boosts
- Doubled chance for special news bulletins.

# New Abilities

- Volume Up: Power of sound based moves are increased by 30%. Used by Loudred/Exploud.
- Lava Body: Attackers who make contact will always get inflicted with burn unless they have immunity. Used by Slugma/Magargo.
- Wildfire: Sp.Atk raises one stage after fainting an opponent. Used by Moltres/Quilava/Typlosion.
- Miracle Blossom: User and ally restore 1/8 HP at the end of every turn. Used by Bayleef/Meganium/Xerneas.
- Scorching Heart: Power of Fire type moves increased by 50%. Used by Solrock/Groudon/Solgaleo.
- Ice Affinity: Power of Ice type moves increased by 50%. Used by Lunatone/Kyogre/Piplup/Prinplup/Empoleon/Lunala.
- Aquatic: Power of Water type moves increased by 50%. Used by Anorith/Armaldo/Dhelmise/Clobbopus/Grapploct.
- Gardener: Power of Grass type moves increased by 50%. Used by Floette/Florges.
- Mystic Mind: Power of Psychic type moves increased by 50%. Used by Psyduck/Golduck.
- Prickly Thorns: Effectively like Rough Skin. Used by Cacnea/Cacturne.
- Aura Sense: User shudders if opponent has super-effective move. Also ignores evasive boosts from target. Used by Riolu/Lucario.
- Soul Siphon: Contact from user steals 1/8 HP from target and heals for the same amount. Used by Duskull/Dusclops/Dusknoir/Palossand/Dhelmise/Corsola(Galarian).
- Bad Luck: Opponent cannot land crits and less likely to land status moves against user. Used by Spiritomb/Cofagrigus.
- Wickedness: User super-effective moves do 25% more damage. Used by Hitmonchan/Mismagius/Braixen/Delphox.
- Spinning Body: User's physical contact moves remove field hazards and raise speed one stage. Used by Pineco/Forretress/Hitmontop/Donphan/Baltoy/Claydol/Solrock/Klink/Klang/Klinklang.
- Evergreen: User takes half damage from Ice type moves and is immune to hail. Used by Grotle/Torterra/Skiddo/Gogoat.
- Hematophagy: Healing effects from drain moves increased by 50%. Used by Zubat/Golbat/Crobat/Yveltal.
- Swordmaster: Power of sword/blade moves increased by 25% (Cut/Leaf Blade/X-Scissor/Sacred Sword/Razor Shell/Secret Sword/Solar Blade/Behemoth Blade). Used by Grovyle/Sceptile/Gallade/Leafeon/Dewott/Samurott/Cobalion/Terrakion/Verizion/Keldeo/Fomantis/Lurantis/Zacian.
- Supercooled: User's Ice type moves are super-effective against Water types. Used by Lapras/Articuno/Glaceon/Aurorus.
- Unsteady: User's evasion increases by one stage when hit. Used by Spinda.
- Disarm: User's contact moves inflict the Embargo status (disable held items) on the target. Used by Meowth/Persian/Pawniard/Bisharp/Meowth(Galarian)
- Painful Burn: If the target is burned, the user's moves have triple the chance to flinch (capped at 60%). Learned by Houndour/Houndoom.
- King's Might: User doesn't need to recharge on moves like Hyper Beam and Giga Impact. Used by Slaking.
- Pleasant Dreams: Heals sleeping Pokemon 1/4 HP every turn. Used by Cresselia.
- Origin: User has 2 additional moveslots that has moves that can be interchangeable outside of battle via the Origin Strand item. Used by Mew.
- Time Traveller: When user HP hits 0, they revert back to their previous HP. Used once per battle for all users, but reset if a user faints an opponent Pokemon. Used by Celebi.
- Wish Maker: User creates a wish on entry. Used by Jirachi.
- Heart Swap: If user makes contact with target, stat changes are swapped. Used by Manaphy.

# Updated Abilities

- Trace: copies the opponent’s highest rated ability that the user doesn’t already have in place of Trace.
- Receiver: copies fainted ally’s highest rated ability that the user doesn’t already have.
- Mummy: replaces all the contact attacker’s abilities with just the Mummy ability.
- Wandering Spirit: replaces each respective ability with the attacker if hit by a contact move unless it is a banned ability.
- Neutralizing Gas: Nullifies other Pokemon abilities unless it is a banned ability like Stance Change. User abilities still active.
- Shell Armor/Battle Armor: Also reduces damage of neutral effective moves by 25%.
- Sand Veil: Increases Sp.Def instead of evasion by one stage in Sandstorm.
- Snow Cloak: Increases Defense instead of evasion by one stage in Hail.
- Slow Start: Timer tuned down to 1 turn from 5.
- Sweet Veil: Also ignores evasion boosts from target.
- Corrosion: Also makes user's Poison moves super effective against Steel types.
- Solar Power: No longer decreases HP. Power modifier changed to 25% from 50%.
- Normalize: Power buffed to 30% from 20%. Also allows user to hit Ghost types.
- Liquid Voice: Also powers up sound moves by 20%.
- Cursed Body: Now always disables the move for just the next turn.
- Keen Eye: Also increases move accuracy by 30%.
- Illuminate: Also ignores opponent evasion boosts.
- Damp: Also grants user immunity to powder based moves and abilities.
- Multitype: Also includes Adaptability and Filter effects.
- Victory Star: User and ally accuracy set to 100%.
- Sturdy will not activate if the user has a max HP of 1.
- Suction Cups will now trap the opposing target if user makes contact instead of making the user immune to forced switch outs.
- Quick Draw: Instead doubles speed when equal or below half health.

# New Moves

- Flint Blade: 80 BP, 100% Acc, Rock type, increased crit ratio. Boosted by Swordmaster ability. Added to Battle Frontier move tutor list. Learned by Leafeon/Dewott/Samurott/Cobalion/Terrakion/Verizion/Keldeo/Fomantis/Lurantis/Zacian/Rockruff/Lycanroc/Gigalith/Onix/Steelix/Omanite/Omastar/Kabuto/Kabutops/Aerodactyl/Anorith/Armaldo/Shieldon/Bastiodon/Binacle/Barbaracle/Rhyhorn/Rhydon/Rhypherior/Aggron/Kleavor/Seviper.
- Blaze Impact: 100 BP, 100% Acc, Fire type, reduces user's speed by one stage. Added to Battle Frontier move tutor list. Learned by Growlith/Arcanine/Ponyta/Rapidash/Flareon/Quilava/Typhlosion/Entei/Torkoal/Tepig/Pignite/Emboar/Heatmor/Litten/Torracat/Incineroar/Scorbunny/Raboot/Cinderace/Charmander/Charmeleon/Charizard/Combusken/Blaziken/Numel/Camerupt/Vulpix/Ninetales/Monferno/Infernape/Heatran/Litleo/Pyroar/Houndour/Houndoom/Carkoal/Coalossal/Groudon/Luxio/Luxray/Phanpy/Donphan/Absol/Skuntank/Zebstrika/Darmanitan/Solgaleo.
- Singularity: A protect move that lowers the speed of foes who make contact by one stage. Learned by Gardevoir on evolution.
- Serpent Dance: Increases the user's special attack and speed by one stage. Added to Battle Frontier move tutor list. Learned by Seviper/Milotic/Serperior/Dunsparce/Ekans/Arbok/Huntail/Gorebyss/Rayquaza/Silicobra/Sandaconda/Giratina/Gyarados/Furret.
-Ice Tusk: 100 BP, 95% Acc, Ice type, increased crit ratio. Learned by Walrein/Mamoswine.
-Hidden Thorns. Grass type Stealth Rock. Will replace Stealth Rock if Stealth Rock is already on the field. Added to Frontier move tutor list. Learned naturally by Roselia/Roserade/Cacnea/Cacturne.

# Updated Moves

- Simple Beam: Replaces opponents abilities with the Simple ability. If opponent has a banned ability such as Stance Change, then they will still keep that ability but the others will be replaced with Simple.
- Worry Seed: Replaces opponents abilities with just the Insomnia ability. If opponent has a banned ability such as Stance Change, then they will still keep that ability but the others will be replaced with Worry Seed.
- Entrainment: Replaces opponents abilities with the user’s abilities. If opponent has a banned ability such as Stance Change, then they will still keep that ability but the others will be replaced with the user’s abilities in their respective slot.
- Skill Swap: swaps the user abilities with the target abilities.  If opponent has a banned ability such as Stance Change, then they will still keep that ability but the others will be replaced with the user’s abilities in their respective slot.
- Gastro Acid: Neutralises target abilities unless it is a banned ability like Stance Change.
- Role Play: replaces the user’s abilities with the target’s abilities except for banned abilities like Stance Change.
- Core Enforcer: Nullifies opponent’s abilities.
- Charge Beam: Now 40 BP, 100% Acc with 100% chance for special attack boost.
- Rock Smash: Now 50 BP with 100% chance for target defense drop.
- Poison Fang: Now has a 100% chance to poison target.
- Cut: Now has 40 BP, 100% Acc and always crits.

# Known Bugs

- Many switch-in abilities (like Frisk and Imposter) don’t activate when both Player Pokemon and opponent Pokemon fainted previous turn (e.g. Destiny Bond) and the Player sends out a Pokemon before the opponent sends out theirs. Solving this will probably involve having to rewrite the code that deals with switch-in abilities. This is probably the same behavior as in vanilla Pokemon Emerald, but I don't see why Trace and Intimidate are allowed to activate whilst others don't, so I'm considering this a bug.
- Abilities that activate at the same time as other abilities on the same Pokemon can have their names in the ability pop-up overwritten. (e.g. Tyranitar with Sand Stream and Unnerve). This is due to how switch-in (and other types) abilities are handled. This could be fixed by setting gLastUsedAbility during the ability battle script with the new setlastusedability command, but this freezes the game when used before calling the ability pop-up. Why? Have no fucking clue.
- Abilities that activate at the same time as other abilities can use wrong strings in the battle message.
- When Rattled is activated, the wrong ability is shown on the pop-up.
- Sometimes when Truant triggers, the wrong ability is shown on the pop-up.
- Intimidate may trigger on fainted mons.
- Frisk may trigger on the wrong Pokemon. Often occurs in Battle Frontier.
- Arena Trap battle message when trying to switch doesn't show the ability string.
- Cloud reflection can be seen in the long grass in Route 120.
- Jumping into long grass from ledge and moving produces incorrect grass animation.
- NPCs can change colour when picking items at BP exchange corner. Palette bug.
- Shop tiles change colour when in shop mode in Mauville sweet shop. Palette bug.
- HP bar in battle may start subtracting at over a thousand health and looks like it drops down to 100% health. Visual error, looks like a full HP bar but not. Cause unknown. Unable to reproduce. Seems to be a very rare bug.
- When a Pokemon evolves by trading, an exp gain sound plays over the Pokemon's cry.
- Wild Deoxys may not regenerate HP bar properly in battle. This is just visual, actual HP values are there. Repeatedly occurs when KOing it from 100% HP.
- Deoxys is also supposed to use a form change animation when changing forms, but it isn't working at all.
- Deoxys may also skip a form change. Repeatedly occurs with Draining Kiss.
- Origin has a visual cursor bug when normal moves are selected, cursor selects 3rd or 4th move, return to main fight menu and then choose Origin move.
- Some Pokemon in PC boxes have the top left corner of their front sprite snipped off. (Dodrio, Alakazam, Kyogre, Lanturn, Aerodactyl, and more)
- Sometimes when battling in the Battle Frontier, a Pokemon will repeatedly consume its held berry. Cause unknown. Haven't been able to reproduce.
- Rarely, a party Pokemon may turn into a bad egg during battles. Cause unknown. Seems to happen with switching. Recommend to keep a lot of save files for safety.
	- Note: Bad Eggs mean that the Pokémon data checksum is invalid. Something is corrupting the Pokémon data.

# Post Launch TODOs

Possible future additions/changes.

- Labels for ability description and IV/EV stats in Pokemon summary screen.
- Pokedex to support regional variants.
- Pokedex to have other data as well. Moves, base stats, evolution requirements, abilities?
- Improve various art assets, mostly trainer pics.
- The berry trees of the type resist berries should have their own colours.
- Implement Zinnia's battle theme. Song is in game data, but not playing well. May be that I haven't figured out the right voicegroup or the song I chose isn't viable to use with GBA sound. Violin sound samples have been added as well just for this song.
- Implement the multi-ability pop-up box in battles. The code is there, I just can't configure it right.
- A contest side-quest with Lisia, much like in ORAS.
- Perhaps a more interesting Winona berry giving event. It's a bit boring to just be given a berry.
- Perhaps a more interesting Tate & Liza event to get Jirachi?
- In-game resource that teaches the player braile. 
- Sort out the online/wireless features. Either find out how to make them work or remove them.
- Better Game Corner games. May be a ton of work though. (Perhaps one could be a Battle Palace style battle where the Player places a bet?)
- Better Battle Frontier level scaling. Open level puts opponent Pokemon to your highest level Pokemon. Should scale all Pokemon to a certain level.
- Make Origin moves use their own PP. PP reduction is done in Battle Script Commands and I currently can't think of a way to differentiate Origin moves and normal moves in `Cmd_ppreduce`. Origin moves not using their own PP is currently a "feature" until this problem can be solved.
- Increase number of PC Pokemon storage boxes.

# Credits

The fine people who worked on pokeemerald and pokeemerald-expansion and helped me with problems:
- DizzyEggg
- LOuroboros/Lunos
- BuffelSaft
- Blackforest92
- ExpoSeed
- SBird1337
- aarant
- SonikkuA-DatH
- Xavion3
- GriffinR
- MGriffin
- AsparagusEduardo
- kleeenexfeu
- Citrus Bolt
- dunsparce9
- Sapphire Jester
- TheXaman
- MeekRhino
- MandL127
- Pyredrid
- ghoulslash
- UltimaSoul
