use strict;
use warnings;
use utf8;
use Log::Nxlog;
use Unicode::Normalize;

sub process
{
    my ( $event ) = @_;
    my $rEvent = Log::Nxlog::get_field($event, 'raw_event');
    if ( defined($rEvent) )
    {
	    my $decomposed = NFKD( $rEvent );
	    $decomposed =~ s/\p{NonspacingMark}//g;
	    Log::Nxlog::set_field_string($event, 'raw_event', $decomposed);
    }

}